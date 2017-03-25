#ifndef NINA_DOMAIN_LATEX_H
#define NINA_DOMAIN_LATEX_H

// STL includes
#include <string>



namespace nina {
namespace domain {
namespace latex {


/// \brief Latex escape string \a string in place
void escape(std::string& string);

/// \brief Latex escape string \a input and return it
std::string escape(const std::string& input);

} // End namespace latex
} // End namespace domain
} // End namespace nina

#endif  // NINA_DOMAIN_LATEX_H
