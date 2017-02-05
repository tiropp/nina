#ifndef NINA_DOMAIN_LATEXHELPERS_H
#define NINA_DOMAIN_LATEXHELPERS_H

// Nina includes
#include <nina/Bank.h>



namespace nina {
namespace domain {


inline
std::string
beginMinipage(unsigned numMinipages)
{
    std::string result;
    if( numMinipages )
        result = "\\begin{minipage}[t]{" + std::to_string(1.0/numMinipages) + "\\textwidth}";
    return result;
}

inline
std::string
endMinipage(unsigned numMinipages)
{
    std::string result;
    if( numMinipages )
        result = "\\end{minipage}%\n";
    return result;
}

inline
std::string
bottomtel(const Invoice& invoice, unsigned numMinipages = 0)
{
    return
        beginMinipage(numMinipages)
        + "Telefon: " + invoice.getSender().getPhone()
        + endMinipage(numMinipages);
}

inline
std::string
bottomnatel(const Invoice& invoice, unsigned numMinipages = 0)
{
    return
        beginMinipage(numMinipages)
        + "Natel: " + invoice.getSender().getMobilePhone()
        + endMinipage(numMinipages);
}

inline
std::string
bottomtelnatel(const Invoice& invoice, unsigned numMinipages = 0)
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

inline
std::string
bottombank(const Invoice& invoice, unsigned numMinipages = 0)
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

inline
std::string
vatNumber(const Invoice& invoice, unsigned numMinipages = 0)
{
    return
        beginMinipage(numMinipages)
        + "MwSt.-Nr.: " + invoice.getVat().getVatNumber()
        + endMinipage(numMinipages);
}

} // End namespace domain
} // End namespace nina

#endif  // NINA_DOMAIN_LATEXHELPERS_H
