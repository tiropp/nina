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

    int infos = 0;
    if( haveContactInfos(invoice) ) infos += 1;
    if( haveBankInfos   (invoice) ) infos += 2;
    if( haveVatInfos    (invoice) ) infos += 4;

    if( !infos )
        return res;

    res =
        std::string("\\setbottomtexttop{") + std::to_string(m_vOffset) + "cm}\n"
        + "\\bottomtext{%\n"
        + "\\fontsize{" + std::to_string(m_fontSize) + "}{" + std::to_string(m_fontSkip) + "}\\selectfont\n"
        + "\\hrule\n";
    switch( infos ) {
        case 1: res += contactInfos(invoice); break;
        case 2: res += bankInfos   (invoice); break;
        case 3: res += contactInfos(invoice, 2) + bankInfos(invoice, 2); break;
        case 4: res += vatInfos    (invoice); break;
        case 5: res += contactInfos(invoice, 2) + vatInfos (invoice, 2); break;
        case 6: res += vatInfos    (invoice, 2) + bankInfos(invoice, 2); break;
        case 7: res += contactInfos(invoice, 3) + bankInfos(invoice, 3) + vatInfos(invoice, 3); break;
        default:
            throw std::logic_error("invalid bottom information");
    }
    res += "}\n";

    return res;
}

bool
BottomField::haveContactInfos(const Invoice& invoice)
{
    if( !invoice.getSettings().isPhoneInBottomField() )
        return false;

    const Sender& sender = invoice.getSender();
    if( !sender.getPhone().empty()       ||
        !sender.getMobilePhone().empty() ||
        !sender.getEmail().empty()       ||
        !sender.getWebpage().empty()      )
        return true;

    return false;
}

bool
BottomField::haveBankInfos(const Invoice& invoice)
{
    return invoice.getSender().getBank().isValid();
}

bool
BottomField::haveVatInfos(const Invoice& invoice)
{
    return invoice.getVat().getShowVat();
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
BottomField::contactInfos(const Invoice& invoice, unsigned numMinipages)
{
    const Sender& sender = invoice.getSender();

    std::string result =
        beginMinipage(numMinipages)
        + "\\begin{tabular}[t]{ll}\n";
    if( !sender.getPhone      ().empty() ) result += "  Telefon: & " + sender.getPhone()       + "\\\\\n";
    if( !sender.getMobilePhone().empty() ) result += "  Natel: & "   + sender.getMobilePhone() + "\\\\\n";
    if( !sender.getEmail      ().empty() ) result += "  E-Mail: & "  + sender.getEmail()       + "\\\\\n";
    if( !sender.getWebpage    ().empty() ) result += "  Webpage: & " + sender.getWebpage()     + "\\\\\n";
    result +=
        "\\end{tabular}"
        + endMinipage(numMinipages);

    return result;
}

std::string
BottomField::bankInfos(const Invoice& invoice, unsigned numMinipages)
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
BottomField::vatInfos(const Invoice& invoice, unsigned numMinipages)
{
    return
        beginMinipage(numMinipages)
        + "MwSt.-Nr.: " + invoice.getVat().getVatNumber()
        + endMinipage(numMinipages);
}

} // End namespace domain
} // End namespace nina
