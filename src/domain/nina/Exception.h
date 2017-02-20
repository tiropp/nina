#ifndef NINA_DOMAIN_EXCEPTION_H
#define NINA_DOMAIN_EXCEPTION_H

// STL includes
#include <stdexcept>
#include <string>



namespace nina {
namespace domain {

/// \brief Base class for all exceptions in this package
class Exception: public std::exception
{
  public:
    Exception(const std::string& msg)
        : m_msg( msg )
    {}

    virtual const char* what() const noexcept { return m_msg.c_str(); }

  private:
    std::string m_msg;
};

} // End namespace domain
} // End namespace nina

#endif  // NINA_DOMAIN_EXCEPTION_H
