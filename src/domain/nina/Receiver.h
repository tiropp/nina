#ifndef NINA_DOMAIN_RECEIVER_H
#define NINA_DOMAIN_RECEIVER_H

// BOOST includes
#include <boost/serialization/access.hpp>

// Nina includes
#include <nina/Address.h>
#include <nina/detail/SerializationHelper.h>



namespace nina {
namespace domain {

class Receiver
{
  public:
    Receiver() {}

  public:
    void setSalutation(const std::string& s)       { m_salutation = s; }
    void setAddress(const Address& address) { m_address = address; }

  public:
    const std::string& getSalutation() const { return m_salutation; }
    const Address& getAddress() const { return m_address; }

  private:
    friend class boost::serialization::access;
    template<class Archive> void serialize(Archive& ar, const unsigned /*version*/) {
        NINA_SERIALIZE(ar, salutation);
        NINA_SERIALIZE(ar, address);
    }

  private:
    std::string m_salutation;
    Address m_address;
};

} // End namespace domain
} // End namespace nina

#endif  // NINA_DOMAIN_RECEIVER_H
