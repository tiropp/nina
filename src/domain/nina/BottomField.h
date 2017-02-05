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
    /// \brief Ctor bottom field creation
    ///
    /// \param[in] vOffset The vertical offset in cm from the top where the bottom field shall be located
    /// \param[in] fontSize The font size to be used in the bottom field
    /// \param[in] fontSkip The font skip size to be used in the bottom field
    BottomField(size_t vOffset, size_t fontSize, size_t fontSkip);


  public:
    /// \brief Return the bottom field information
    std::string operator()(const Invoice& invoice);

  private:
    std::string phone(const Invoice& invoice, unsigned numMinipages = 0);
    std::string mobilePhone(const Invoice& invoice, unsigned numMinipages = 0);
    std::string phoneAndMobilePhone(const Invoice& invoice, unsigned numMinipages = 0);
    std::string bank(const Invoice& invoice, unsigned numMinipages = 0);
    std::string vatNumber(const Invoice& invoice, unsigned numMinipages = 0);
    std::string beginMinipage(unsigned numMinipages);
    std::string endMinipage  (unsigned numMinipages);

  private:
    size_t m_vOffset;
    size_t m_fontSize;
    size_t m_fontSkip;
};

} // End namespace domain
} // End namespace nina

#endif  // NINA_DOMAIN_BOTTOMFILED_H
