#include "PdfCreator.h"

// STL includes
#include <sstream>

// BOOST includes
#include <boost/filesystem/fstream.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <boost/algorithm/string/trim.hpp>

// Nina includes
#include <nina/Invoice.h>
#include <nina/BottomField.h>
#include <nina/Latex.h>

// Namespace aliases
namespace fs = boost::filesystem;


namespace {
    const char* kRComName     = "rcom";
    const char* kRComFilename = "rcom.sty";
} // End unnamed namespace



namespace nina {
namespace domain {


PdfCreator::PdfCreator()
{
    createWorkingDir();
    writeRComFile();
}

void
PdfCreator::createWorkingDir()
{
    m_workingDir = getTmpFilename();
    fs::create_directory( m_workingDir );
}

fs::path
PdfCreator::getTmpFilename() const
{
    return fs::temp_directory_path() / fs::unique_path();
}

void
PdfCreator::writeRComFile()
{
    auto filename = m_workingDir / fs::path(kRComFilename);
    fs::ofstream rcom( filename );
    rcom << "\\NeedsTeXFormat{LaTeX2e}\n"
         << "\\ProvidesPackage{rcom}[2004/03/09 v0.1 Coms fuer Rechnung]\n"
         << "\\newskip\\skip@lines \\skip@lines=2.5pt\n"
         << "\\def\\dline#1{%\n"
         << "\\@cline#1\\@nil\n"
         << "\\cr\\noalign{\\vskip-\\f@baselineskip\\vskip\\skip@lines}\n"
         << "\\@cline#1\\@nil}\n"
         << "\\endinput\n";
}

PdfCreator::~PdfCreator()
{
    removeWorkingDir();
}

void
PdfCreator::removeWorkingDir()
{
    fs::remove_all( m_workingDir );
}


fs::path
PdfCreator::operator()(const Invoice& invoice, std::string& errorMsg)
{
    auto latexFile = WriteLatexFile( invoice );
    errorMsg = CreatePdf( latexFile );

    auto pdfFile( latexFile );
    pdfFile.replace_extension("pdf");
    return pdfFile;
}

fs::path
PdfCreator::WriteLatexFile(const Invoice& invoice)
{
    auto filename = m_workingDir / fs::path("invoice.tex");
    fs::ofstream fs( filename );

    fs << "\\documentclass[a4paper,12pt]{dinbrief}\n"
       << "\\usepackage[utf8]{inputenc}\n"
       << "\\usepackage[ngerman]{babel}\n"
       << "\\usepackage{a4wide}\n"
       << "\\usepackage{units}\n"
       << "\\setlength{\\textheight}{25cm}\n"
       << "\\pagestyle{empty}\n"
       << "\\usepackage{supertabular}\n"
       << "\\usepackage{" << kRComName << "}\n";

    // Date
    if( !invoice.getDate().useToday() )
        fs << "\\date {" << invoice.getDate().toString() << "}\n";

    // Title
    fs << "\\subject {\\LARGE\\textbf{" << invoice.getMisc().getTitle() << "}}\n"
       << "\\renewcommand{\\signmsgnew}{}\n"
       << "\\renewcommand{\\yourmailmsg}{}\n"
       << "\\newcommand{\\thickhline}[1]{%\n"
       << "  \\noalign{\\global\\arrayrulewidth#1}\\hline\n"
       << "  \\noalign{\\global\\arrayrulewidth#1}%\n"
       << "}\n";


    // Phone, MobilePhone
    if( !invoice.getSettings().isPhoneInBottomField() ) {
        if( !invoice.getSender().getPhone().empty() ) {
            if( !invoice.getSender().getMobilePhone().empty() )
                fs << "\\enabledraftstandard\n"
                   << "\\phone{}{" << invoice.getSender().getPhone() << "}\n"
                   << "\\renewcommand{\\writermsg}{, Natel}\n"
                   << "\\writer{\\\\" << invoice.getSender().getMobilePhone() << "}\n";
            else
                fs << "\\enabledraftstandard\n"
                   << "\\phone{}{" << invoice.getSender().getPhone() << "}\n"
                   << "\\renewcommand{\\writermsg}{}\n"
                   << "\\writer{}\n";
        }
        else {
            if( !invoice.getSender().getMobilePhone().empty() )
                fs << "\\enabledraftstandard\n"
                   << "\\renewcommand{\\phonemsg}{Natel}\n"
                   << "\\phone{}{" << invoice.getSender().getMobilePhone() << "}\n"
                   << "\\renewcommand{\\writermsg}{}\n"
                   << "\\writer{}\n";
        }
    }

    BottomField bottomField(27/*cm*/, 9/*pt*/, 9/*pt*/);
    fs << bottomField(invoice);

    // sender address
    const Sender& sender = invoice.getSender();
    const Address& addr = sender.getAddress();
    fs << "\\address{\\vspace{40pt}\n";
    if( !addr.getName().empty()    )                             fs << "         " << addr.getName();
    if( !addr.getCompany().empty() )                             fs << "\\\\\n         " << addr.getCompany();
    if( !addr.getStreet().empty()  )                             fs << "\\\\\n         " << addr.getStreet();
    if( addr.getZipCode() && !addr.getPlace().empty() )          fs << "\\\\\n         " << addr.getZipCode() << " " << addr.getPlace();
    else if( addr.getZipCode() )                                 fs << "\\\\\n         " << addr.getZipCode();
    else if( !addr.getPlace().empty() )                          fs << "\\\\\n         " << addr.getPlace();
    if( !addr.getCountry().empty() )                             fs << "\\\\\n         " << addr.getCountry();
    fs << "}\n";

    // place, signature
    fs << "\\place{" << addr.getPlace() << "}\n"
       << "\\signature{";
    if( !invoice.getSender().getSignature().empty() ) fs << invoice.getSender().getSignature();
    else                                                fs << addr.getName();
    fs << "}\n";

    // writing address position command
    //---------------------------------
    // Set the distrance for the address field from the left border to 11 cm
    fs << "\\setaddressllhpos{120mm}\n";
    //
    // Distance of the bottom line of the address field from the top of the page
    fs << "\\setaddressllvpos{45mm}";
    //
    // Width of the address field
    fs << "\\setaddresswidth{80mm}";
    //
    // Height of the address field
    //fs << "\\setaddressheight{30mm}";
    //
    // The address field is not surrounded by top and bottom lines
    fs << "\\nowindowrules\n";
    //
    // No markings on the left side to indicate the folding position
    fs << "\\nowindowtics\n";
    //
    // Distance of the reference line (telephone, date, place .. ) from the top
    // of the page.
    fs << "\\setreflinetop{7.5cm}\n";

    // writing being document command
    //-------------------------------
    fs << "\\begin{document}\n";


    // writing fontype command
    //----------------------------
    fs << "\\fontencoding{OT1}\n"
       << "\\fontfamily{cmss}\n"
       << "\\fontseries{m}\n"
       << "\\fontshape{n}\n"
       << "\\selectfont\n";


    // writing begin letter command
    //----------------------------
    const Receiver& recv     = invoice.getReceiver();
    const Address&  recvAddr = recv.getAddress();
    fs << "\\begin{letter}{\n";
    if( !recv.getSalutation().empty() )     fs << "               " << recv.getSalutation() << "\\\\\n";
    if( !recvAddr.getName().empty() )       fs << "               " << recvAddr.getName() << "\\\\\n";
    if( !recvAddr.getCompany().empty() )    fs << "               " << recvAddr.getCompany() << "\\\\\n";
    if( !recvAddr.getStreet().empty() )     fs << "               " << recvAddr.getStreet() << "\\\\\n";
    if(  recvAddr.usePoBox() )              fs << "               Postfach\\\\\n";
    if(  recvAddr.getZipCode() )            fs << "               " << recvAddr.getZipCode();
    if( !recvAddr.getPlace().empty() )      fs << " " << recvAddr.getPlace();
    if( !recvAddr.getCountry().empty() )    fs << "\\\\\n               " << recvAddr.getCountry();
    fs << "}\n";

    // writing opening command
    //------------------------
    fs << "\\opening{}\n";

    // writing fontsize command
    //-------------------------
    fs << "\\fontsize{" << invoice.getSettings().getFontSize() << "pt}{" << invoice.getSettings().getFontSkip() << "pt}\n"
       << "\\selectfont\n";

    // Actual invoice
    if( !invoice.getMisc().getTextBeforePositions().empty() )
        fs << invoice.getMisc().getTextBeforePositions() << "\\\\\n\n";

    fs << "\\newlength{\\beschwidth}\n"                 // definiere zuerst die Breite
       << "\\setlength{\\beschwidth}{0.55\\textwidth}\n" // des Besch-Feldes
       << "\\newlength{\\beschtmpwidth}\n"
       << "\\newlength{\\parindentbesch}\n"             // def. die Einschublänge
       << "\\setlength{\\parindentbesch}{5mm}\n"

       // vspace{12pt} erzeugt zusätzlichen Abst. nach Tabellenkopf
       << "\\tablefirsthead{\\multicolumn{1}{l}{\\hspace{-0.5em}\\textbf{Beschreibung}} & "
       << "\\multicolumn{1}{r}{\\textbf{Menge}} & "
       << "\\multicolumn{1}{r}{\\textbf{Einzelpreis}} & "
       << "\\multicolumn{1}{r}{\\textbf{Gesamtpreis}}\\\\}\n"
       << "\\tablehead{\\multicolumn{1}{l}{\\hspace{-0.5em}\\textbf{Beschreibung}} & "
       << "\\multicolumn{1}{r}{\\textbf{Anzahl}} & "
       << "\\multicolumn{1}{r}{\\textbf{Fr./Einheit}} & "
       << "\\multicolumn{1}{r}{\\textbf{Fr./Pos.}}\\\\}\n"
       << "\\begin{supertabular*}{\\textwidth}{@{\\extracolsep{\\fill}}p{\\beschwidth}rrr}\n"

       // top rule
       << "\\thickhline{2pt}\n"
       << "\\rule{0pt}{1.5em}%\n";

    size_t posIndex = 0;
    for(const Position& pos : invoice.getPositions()) {
        // prüft ob ein GRATIS ins besch-Feld eingefügt werden muss
        std::string description = pos.getDescription();
        if( pos.isFreeOfCharge() )
            description += ", {\\bf GRATIS}";


        // prüft ob ein EINSCHUB vorgenommen werden muss
        // setze zuerst die Breite des Feldes auf Normalgrösse
        fs << "\\setlength{\\beschtmpwidth}{\\beschwidth}";
        size_t countAt = std::count(description.begin(), description.end(), '@');
        for(size_t k = 0; k <= countAt; ++k) {
            if( description[k] == '@' )
                fs << "\\hspace{5mm}"
                   << "\\addtolength{\\beschtmpwidth}{-\\parindentbesch}";
            else {
                std::string descr = description.substr(k);
                boost::trim(descr);
                latex::escapeTableContents( descr );
                fs << descr;
                if( posIndex < invoice.getPositions().getSize() - 1 )                          // nach jedem Posten einen Abst. von
                    fs << "\\vspace{" << invoice.getSettings().getPositionSkip() << "pt}";  // der Grösse posskip einfügen,
                                                                                              // nicht nach letzten
            }

            ++posIndex;
        }

        // prüft ob es sich um einen PAUSCHALBETRAG handelt
        if( pos.isFreeOfCharge() || pos.hasOnlyDescription() )
            fs << "\\\\\n";
        else if( pos.isFlatPrice() )
            fs << " & & & " << pos.getPrice().toString(0.01) << "\\\\\n";
        else
            fs << " & " << pos.getNumUnits() << " " << latex::escape(pos.getUnit()) << " & " << pos.getPricePerUnit().toString(0.01) << " & " << pos.getPrice().toString(0.01) << "\\\\\n";
    }


    fs << "\\thickhline{2pt}\n"  // Zw.einschub
       << "\\rule{0pt}{1.5em}%\n";
    if( !invoice.getVat().getShowVat() )
        fs << "\\textbf{Gesamtbetrag} & & &\\textbf{" << invoice.getPositions().getPrice().toString(0.05) << "}\\\\\n";
    else {
        const Money  price   = invoice.getPositions().getPrice(0.01);
        const double taxRate = invoice.getVat().getTaxRate();
        Money  tax           = (price * (taxRate / 100)).round(0.01);
        if( invoice.getVat().getPricesInclVat() ) {
            fs << "\\textbf{Gesamtbetrag inkl. MwSt.} & & &\\textbf{" << price.toString(0.05) << "}\\\\\n"
               << "Enthält \\unit[" << taxRate << "]{\\%}  MwSt. & & & " << tax.toString(0.01) << "\\\\\n";
        }
        else {
            fs << "Gesamtbetrag exkl. MwSt. & & & " << price.toString(0.01) << "\\\\\n"
               << "Mehrwertsteuer \\unit[" << taxRate << "]{\\%} & & & " << tax.toString(0.01) << "\\\\\n";

            const Money total = tax + price;
            const Money roundMistake = total.roundMistake(0.05);
            if( roundMistake != Money() )
                fs << "Rundungsbetrag & & & " << roundMistake.toString(0.01) << "\\\\\n";

            fs << "\\textbf{Gesamtbetrag inkl. MwSt.} & & &\\textbf{" << total.toString(0.05) << "}\\\\\n";
        }
    }
    fs << "\\end{supertabular*}\n";

    if( !invoice.getMisc().getTextAfterPositions().empty() )
        fs << "\\\\[.75cm]" << invoice.getMisc().getTextAfterPositions() << "\\\\\n";

    fs << "\\\\[0.75cm]\n"
       << "\\center{\\large Danke f\"ur den Auftrag}\\flushleft\n"
       << "\\closing{" << invoice.getSender().getGreetings() << "}\n"
       << "\\end{letter}\n"
       << "\\end{document}\n";

    return filename;
}

std::string
PdfCreator::CreatePdf(const fs::path& path)
{
    std::string msg;

    std::stringstream command;
    command << "pdflatex"
            << " -interaction batchmode"
            << " -output-directory \"" << path.parent_path().string() << "\""
            << " \"" + path.string() + "\"";
    int ret= system(command.str().c_str());
    if( ret )
        msg = "pdflatex error: " + std::to_string(ret);

    return msg;
}

} // End namespace domain
} // End namespace nina
