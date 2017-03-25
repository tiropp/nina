#include "Latex.h"

// BOOST includes
#include <boost/algorithm/string/replace.hpp>



namespace nina {
namespace domain {
namespace latex {


void
escape(std::string& string)
{
    boost::replace_all(string, "\n", "\\\\");
    boost::replace_all(string, "&", "\\&");
}


} // End namespace latex
} // End namespace domain
} // End namespace nina
