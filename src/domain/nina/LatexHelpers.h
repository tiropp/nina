#ifndef NINA_DOMAIN_LATEXHELPERS_H
#define NINA_DOMAIN_LATEXHELPERS_H

// Nina includes
#include <nina/Bank.h>



namespace nina {
namespace domain {

//
// Bottomfield  functions
//
inline
void
bottomtel(std::ofstream& fs, const std::string& phone)
{
    fs << "Telefon: " << phone;
}

inline
void
bottomnatel(std::ofstream& fs, const std::string& mobilePhone)
{
    fs << "Natel: " << mobilePhone;
}

inline
void
bottomtelnatel(std::ofstream& fs, const std::string& phone, const std::string& mobilePhone)
{
    fs << "\\begin{tabular}{ll}"
       << "Telefon: & " << phone << "\\\\"
       << "Natel: & " << mobilePhone << "\\\\"
       << "\\end{tabular}";
}

inline
void
bottombank(std::ofstream& fs, const Bank& bank)
{
    fs << "\\begin{tabular}{lll}"
       << "Bankverbindung: & \\multicolumn{2}{l}{" << bank.getName() << "}\\\\";
    if( !bank.getBic().empty() )
        fs << "                & BLZ & " << bank.getBic() << "\\\\";
    if( !bank.getAccount().empty() )
        fs << "                & Kto. & " << bank.getAccount() << "\\\\";
    fs << "\\end{tabular}";
}

/// \brief Begin minipage
inline
void
bm(std::ofstream& fs)
{
    fs << "\\begin{minipage}{0.5\\textwidth}";
}

/// \brief End minipage
inline
void
em(std::ofstream& fs)
{
    fs << "\\end{minipage}";
}


} // End namespace domain
} // End namespace nina

#endif  // NINA_DOMAIN_LATEXHELPERS_H
