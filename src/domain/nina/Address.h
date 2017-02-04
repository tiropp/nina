#ifndef NINA_DOMAIN_ADDRESS_H
#define NINA_DOMAIN_ADDRESS_H

// STL includes
#include <string>

// BOOST includes
#include <boost/serialization/access.hpp>

// Nina includes
#include <nina/detail/SerializationHelper.h>



namespace nina {
namespace domain {

class Address
{
  public:
    const std::string& getSalutation() const { return m_salutation; }
    const std::string& getName()    const { return m_name; }
    const std::string& getCompany() const { return m_company; }
    const std::string& getStreet()  const { return m_street; }

    /// \brief Return the zip code
    ///
    /// An invalid zip code returns 0
    size_t getZipCode() const { return m_zipCode; }

    const std::string& getPlace()   const { return m_place; }
    const std::string& getCountry()  const { return m_country; }
    bool               usePoBox()   const { return m_usePoBox; }

  public:
    void setSalutation(const std::string& s)       { m_salutation = s; }
    void setName      (const std::string& name)    { m_name = name; }
    void setCompany   (const std::string& company) { m_company = company; }
    void setStreet    (const std::string& street)  { m_street = street; }
    void setZipCode   (size_t zipCode)             { m_zipCode = zipCode; }
    void setPlace     (const std::string& place)   { m_place = place; }
    void setCountry   (const std::string& country) { m_country = country; }
    void setUsePoBox  (bool use)                   { m_usePoBox = use; }

  private:
    friend class boost::serialization::access;
    template<class Archive> void serialize(Archive& ar, const unsigned /*version*/) {
        NINA_SERIALIZE(ar, salutation);
        NINA_SERIALIZE(ar, name);
        NINA_SERIALIZE(ar, company);
        NINA_SERIALIZE(ar, street);
        NINA_SERIALIZE(ar, zipCode);
        NINA_SERIALIZE(ar, place);
        NINA_SERIALIZE(ar, country);
        NINA_SERIALIZE(ar, usePoBox);
    }

  private:
    std::string m_salutation;
    std::string m_name;
    std::string m_company;
    std::string m_street;
    std::size_t m_zipCode;
    std::string m_place;
    std::string m_country;
    bool        m_usePoBox;
};

} // End namespace domain
} // End namespace nina

#endif  // NINA_DOMAIN_ADDRESS_H
