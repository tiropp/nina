#include "PdfCreator.h"

// STL includes
#include <sstream>

// BOOST includes
#include <boost/filesystem/fstream.hpp>

// Nina includes
#include <nina/Invoice.h>
#include <nina/LatexHelpers.h>

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
       << "\\setlength{\\textheight}{25cm}\n"
       << "\\pagestyle{empty}\n"
       << "\\usepackage{supertabular}\n"
       << "\\usepackage{" << kRComName << "}\n";

    // Date
    if( !invoice.getDate().useToday() )
        fs << "\\date {" << invoice.getDate().toString() << "}\n";

    // Title
    fs << "\\subject {\\LARGE\\textbf{" << invoice.getTitle() << "}}\n"
       << "\\renewcommand{\\signmsgnew}{}\n"
       << "\\renewcommand{\\yourmailmsg}{}\n";

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

    // BottomField
    //   bottom = 1 : tel in bottom
    //   bottom = 2 : natel in bottom
    //   bottom = 4 : bankverbindung in bottom
    int bottom = 0;
    if( invoice.getSettings().isPhoneInBottomField() && !invoice.getSender().getPhone().empty() )
        bottom += 1;
    if( invoice.getSettings().isPhoneInBottomField() && !invoice.getSender().getMobilePhone().empty() )
        bottom += 2;
    if( invoice.getSender().getBank().isValid() )
        bottom += 4;
    //
    if( bottom > 0 ) {
        fs << "\\setbottomtexttop{27cm}"
           << "\\bottomtext{\\hrule";
        switch( bottom ) {
        case 1:	bottomtel     (fs, invoice.getSender().getPhone()); break;
        case 2:	bottomnatel   (fs, invoice.getSender().getMobilePhone()); break;
        case 3:	bottomtelnatel(fs, invoice.getSender().getPhone(), invoice.getSender().getMobilePhone()); break;
        case 4:	bottombank(fs, invoice.getSender().getBank()); break;
        case 5:	bm(fs);bottomtel     (fs, invoice.getSender().getPhone());                                       em(fs); bm(fs); bottombank(fs, invoice.getSender().getBank());em(fs); break;
        case 6:	bm(fs);bottomnatel   (fs, invoice.getSender().getMobilePhone());                                 em(fs); bm(fs); bottombank(fs, invoice.getSender().getBank());em(fs); break;
        case 7:	bm(fs);bottomtelnatel(fs, invoice.getSender().getPhone(), invoice.getSender().getMobilePhone()); em(fs); bm(fs); bottombank(fs, invoice.getSender().getBank());em(fs); break;
        default: 	break;
        }
        fs << "}";
    }

    // sender address
    const Address& addr = invoice.getSender().getAddress();
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
    const Address& recvAddr = invoice.getReceiver().getAddress();
    fs << "\\begin{letter}{\n";
    if( !recvAddr.getSalutation().empty() ) fs << "               " << recvAddr.getSalutation() << "\\\\\n";
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
    if( !invoice.getTextBeforePositions().empty() )
        fs << invoice.getTextBeforePositions() << "\\\\\n\n";

    fs << "\\newlength{\\beschwidth}"                 // definiere zuerst die Breite
       << "\\setlength{\\beschwidth}{0.6\\textwidth}" // des Besch-Feldes
       << "\\newlength{\\beschtmpwidth}"
       << "\\newlength{\\parindentbesch}"             // def. die Einschublänge
       << "\\setlength{\\parindentbesch}{5mm}"

       // vspace{12pt} erzeugt zusätzlichen Abst. nach Tabellenkopf
       << "\\tablefirsthead{\\multicolumn{1}{l}{\\hspace{-0.5em}\\textbf{Beschreibung}} &"
       << "\\multicolumn{1}{r}{\\textbf{Anzahl}} &"
       << "\\multicolumn{1}{r}{\\textbf{Fr./Einheit}} &"
       << "\\multicolumn{1}{r}{\\textbf{Fr./Pos.}}\\vspace{12pt}\\\\}"
       << "\\tablehead{\\multicolumn{1}{l}{\\hspace{-0.5em}\\textbf{Beschreibung}} &"
       << "\\multicolumn{1}{r}{\\textbf{Anzahl}} &"
       << "\\multicolumn{1}{r}{\\textbf{Fr./Einheit}} &"
       << "\\multicolumn{1}{r}{\\textbf{Fr./Pos.}}\\vspace{12pt}\\\\}"
       << "\\begin{supertabular*}{\\textwidth}{@{\\extracolsep{\\fill}}p{\\beschwidth}rrr}";

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
                fs << "\\begin{minipage}{\\beschtmpwidth}"
                   << description.substr(k)
                   << "\\end{minipage}";
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
            fs << " & & & " << pos.getPrice() << "\\\\\n";
        else
            fs << " & " << pos.getNumUnits() << " " << pos.getUnit() << " & " << pos.getPricePerUnit() << " & " << pos.getPrice() << "\\\\\n";
    }


    fs << "\\cline{4-4}\\\\"  // Zw.einschub
       << "\\textbf{Total} & & &\\textbf{" << invoice.getPositions().getPrice() << "}\\\\\n"
       << "\\dline{4-4}\n"
       << "\\end{supertabular*}\n";

    if( !invoice.getTextAfterPositions().empty() )
        fs << "\\\\[.75cm]" << invoice.getTextAfterPositions() << "\\\\\n";

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
            << " -output-directory \"" << path.parent_path().native() << "\""
            << " \"" + path.native() + "\"";
    int ret= system(command.str().c_str());
    if( ret )
        msg = "pdflatex error: " + std::to_string(ret);

    return msg;
}

} // End namespace domain
} // End namespace nina
