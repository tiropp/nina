#ifndef NINA_DOMAIN_SENDER_H
#define NINA_DOMAIN_SENDER_H

// STL includes
#include <string>

// BOOST includes
#include <boost/serialization/access.hpp>

// Nina includes
#include <nina/Address.h>
#include <nina/Bank.h>
#include <nina/detail/SerializationHelper.h>



namespace nina {
namespace domain {

class Sender
{
  public:
    Sender() {}
    Sender(const Address& address) : m_address( address ) {}

  public:
    void setAddress(const Address& address) { m_address = address; }
    void setBank(const Bank& bank) { m_bank = bank; }
    void setPhone(const std::string& phone) { m_phone = phone; }
    void setMobilePhone(const std::string& mobilePhone) { m_mobilePhone = mobilePhone; }
    void setEmail(const std::string& email) { m_email = email; }
    void setWebpage(const std::string& webpage) { m_webpage = webpage; }
    void setSignature(const std::string& signature) { m_signature = signature; }
    void setGreetings(const std::string& greetings) { m_greetings = greetings; }

  public:
    const Address& getAddress() const { return m_address; }
    const Bank& getBank() const { return m_bank; }
    const std::string& getPhone() const { return m_phone; }
    const std::string& getMobilePhone() const { return m_mobilePhone; }
    const std::string& getEmail() const { return m_email; }
    const std::string& getWebpage() const { return m_webpage; }
    const std::string& getSignature() const { return m_signature; }
    const std::string& getGreetings() const { return m_greetings; }

  private:
    friend class boost::serialization::access;
    template<class Archive> void serialize(Archive& ar, const unsigned /*version*/) {
        NINA_SERIALIZE(ar, address);
        NINA_SERIALIZE(ar, bank);
        NINA_SERIALIZE(ar, phone);
        NINA_SERIALIZE(ar, mobilePhone);
        NINA_SERIALIZE(ar, email);
        NINA_SERIALIZE(ar, webpage);
        NINA_SERIALIZE(ar, signature);
        NINA_SERIALIZE(ar, greetings);
    }

  private:
    Address m_address;
    Bank m_bank;
    std::string m_phone;
    std::string m_mobilePhone;
    std::string m_email;
    std::string m_webpage;
    std::string m_signature;
    std::string m_greetings;
};

} // End namespace domain
} // End namespace nina

#endif  // NINA_DOMAIN_SENDER_H
