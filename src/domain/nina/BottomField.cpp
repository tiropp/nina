#include "BottomField.h"

// Nina includes
#include <nina/Invoice.h>
#include <nina/Sender.h>
#include <nina/Bank.h>
#include <nina/Vat.h>



namespace nina {
namespace domain {

BottomField::BottomField(size_t vOffset, size_t fontSize, size_t fontSkip)
    : m_vOffset( vOffset )
    , m_fontSize( fontSize )
    , m_fontSkip( fontSkip )
{
}

std::string
BottomField::operator()(const Invoice& invoice)
{
    std::string res;

    // BottomField
    //   bottom = 1 : tel in bottom
    //   bottom = 2 : natel in bottom
    //   bottom = 4 : bankverbindung in bottom
    //   bottom = 8 : VAT
    int bottom = 0;
    if( invoice.getSettings().isPhoneInBottomField() && !invoice.getSender().getPhone().empty() )
        bottom += 1;
    if( invoice.getSettings().isPhoneInBottomField() && !invoice.getSender().getMobilePhone().empty() )
        bottom += 2;
    if( invoice.getSender().getBank().isValid() )
        bottom += 4;
    if( invoice.getVat().getShowVat() )
        bottom += 8;

    if( bottom == 0 )
        return res;

    res =
        std::string("\\setbottomtexttop{") + std::to_string(m_vOffset) + "cm}\n"
        + "\\bottomtext{%\n"
        + "\\fontsize{" + std::to_string(m_fontSize) + "}{" + std::to_string(m_fontSkip) + "}\\selectfont\n"
        + "\\hrule\n";
    switch( bottom ) {
        case  1: res += phone              (invoice); break;
        case  2: res += mobilePhone        (invoice); break;
        case  3: res += phoneAndMobilePhone(invoice); break;
        case  4: res += bank               (invoice); break;
        case  5: res += phone              (invoice, 2) + bank(invoice, 2); break;
        case  6: res += mobilePhone        (invoice, 2) + bank(invoice, 2); break;
        case  7: res += phoneAndMobilePhone(invoice, 2) + bank(invoice, 2); break;
        case  8: res += vatNumber(invoice); break;
        case  9: res += phone              (invoice, 2) + vatNumber(invoice, 2); break;
        case 10: res += mobilePhone        (invoice, 2) + vatNumber(invoice, 2); break;
        case 11: res += phoneAndMobilePhone(invoice, 2) + vatNumber(invoice, 2); break;
        case 12: res += vatNumber          (invoice, 2) + bank     (invoice, 2); break;
        case 13: res += phone              (invoice, 3) + bank(invoice, 3) + vatNumber(invoice, 3); break;
        case 14: res += mobilePhone        (invoice, 3) + bank(invoice, 3) + vatNumber(invoice, 3); break;
        case 15: res += phoneAndMobilePhone(invoice, 3) + bank(invoice, 3) + vatNumber(invoice, 3); break;
        default:
            throw std::logic_error("invalid bottom information");
        }
    res += "}\n";

    return res;
}

std::string
BottomField::beginMinipage(unsigned numMinipages)
{
    std::string result;
    if( numMinipages )
        result = "\\begin{minipage}[t]{" + std::to_string(1.0/numMinipages) + "\\textwidth}";
    return result;
}

std::string
BottomField::endMinipage(unsigned numMinipages)
{
    std::string result;
    if( numMinipages )
        result = "\\end{minipage}%\n";
    return result;
}

std::string
BottomField::phone(const Invoice& invoice, unsigned numMinipages)
{
    return
        beginMinipage(numMinipages)
        + "Telefon: " + invoice.getSender().getPhone()
        + endMinipage(numMinipages);
}

std::string
BottomField::mobilePhone(const Invoice& invoice, unsigned numMinipages)
{
    return
        beginMinipage(numMinipages)
        + "Natel: " + invoice.getSender().getMobilePhone()
        + endMinipage(numMinipages);
}

std::string
BottomField::phoneAndMobilePhone(const Invoice& invoice, unsigned numMinipages)
{
    const Sender& sender = invoice.getSender();
    return
        beginMinipage(numMinipages)
        + "\\begin{tabular}[t]{ll}\n"
        + std::string("  Telefon: & ") + sender.getPhone() + "\\\\\n"
        + std::string("  Natel: & ")   + sender.getMobilePhone() + "\\\\\n"
        + std::string("\\end{tabular}\n")
        + endMinipage(numMinipages);
}

std::string
BottomField::bank(const Invoice& invoice, unsigned numMinipages)
{
    const Bank& bank = invoice.getSender().getBank();
    std::string result =
        beginMinipage(numMinipages)
        + std::string("\\hspace{1em}\\begin{tabular}[t]{ll}\n")
        + "\\multicolumn{2}{l}{" + bank.getName() + "}\\\\\n";
    if( !bank.getAccount().empty() )
        result += "Kto.-Nr. & " + bank.getAccount() + "\\\\\n";
    if( !bank.getBic().empty() )
        result += "Swift/BIC & " + bank.getBic() + "\\\\\n";
    if( !bank.getIban().empty() )
        result += "IBAN & " + bank.getIban() + "\\\\\n";
    result +=
        "\\end{tabular}\n"
        + endMinipage(numMinipages);
    return result;
}

std::string
BottomField::vatNumber(const Invoice& invoice, unsigned numMinipages)
{
    return
        beginMinipage(numMinipages)
        + "MwSt.-Nr.: " + invoice.getVat().getVatNumber()
        + endMinipage(numMinipages);
}

} // End namespace domain
} // End namespace nina
