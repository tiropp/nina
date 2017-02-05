#ifndef NINA_DOMAIN_BOTTOMFILED_H
#define NINA_DOMAIN_BOTTOMFILED_H

// STL includes
#include <string>

// Fwd declarations
namespace nina { namespace domain { class Invoice; } }



namespace nina {
namespace domain {

class BottomField
{
  public:
    static std::string phone(const Invoice& invoice, unsigned numMinipages = 0);
    static std::string mobilePhone(const Invoice& invoice, unsigned numMinipages = 0);
    static std::string phoneAndMobilePhone(const Invoice& invoice, unsigned numMinipages = 0);
    static std::string bank(const Invoice& invoice, unsigned numMinipages = 0);
    static std::string vatNumber(const Invoice& invoice, unsigned numMinipages = 0);

  private:
    static std::string beginMinipage(unsigned numMinipages);
    static std::string endMinipage  (unsigned numMinipages);
};

} // End namespace domain
} // End namespace nina

#endif  // NINA_DOMAIN_BOTTOMFILED_H
