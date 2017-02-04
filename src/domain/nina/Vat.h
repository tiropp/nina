 #ifndef NINA_DOMAIN_VAT_H
#define NINA_DOMAIN_VAT_H

// STL includes
#include <string>

// BOOST includes
#include <boost/serialization/access.hpp>

// Nina includes
#include <nina/detail/SerializationHelper.h>



namespace nina {
namespace domain {

class Vat
{
  public:
    Vat();
    Vat(bool pricesInclVat, const std::string& vatNumber, double taxRate);

  public:
    bool getShowVat() const { return m_showVat; }
    bool getPricesInclVat() const { return m_pricesInclVat; }
    const std::string& getVatNumber() const { return m_vatNumber; }
    double getTaxRate() const { return m_taxRate; }

  private:
    friend class boost::serialization::access;
    template<class Archive> void serialize(Archive& ar, const unsigned /*version*/) {
        NINA_SERIALIZE(ar, showVat);
        NINA_SERIALIZE(ar, pricesInclVat);
        NINA_SERIALIZE(ar, vatNumber);
        NINA_SERIALIZE(ar, taxRate);
    }

  private:
    bool m_showVat;
    bool m_pricesInclVat;
    std::string m_vatNumber;
    double m_taxRate;
};

} // End namespace domain
} // End namespace nina

#endif  // NINA_DOMAIN_VAT_H
