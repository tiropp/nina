#include "BottomField.h"

// Nina includes
#include <nina/Invoice.h>
#include <nina/Sender.h>
#include <nina/Bank.h>
#include <nina/Vat.h>



namespace nina {
namespace domain {


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
        + "\nBankverbindung:\\\\\n"
        + std::string("\\hspace{1em}\\begin{tabular}[t]{ll}\n")
        + "\\multicolumn{2}{l}{" + bank.getName() + "}\\\\\n";
    if( !bank.getBic().empty() )
        result += "BLZ & " + bank.getBic() + "\\\\\n";
    if( !bank.getAccount().empty() )
        result += "Kto. & " + bank.getAccount() + "\\\\\n";
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
