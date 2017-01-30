#ifndef NINA_DOMAIN_SENDER_H
#define NINA_DOMAIN_SENDER_H

// STL includes
#include <string>

// Nina includes
#include <nina/Address.h>
#include <nina/Bank.h>



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
    void setSignature(const std::string& signature) { m_signature = signature; }
    void setGreetings(const std::string& greetings) { m_greetings = greetings; }

  public:
    const Address& getAddress() const { return m_address; }
    const Bank& getBank() const { return m_bank; }
    const std::string& getPhone() const { return m_phone; }
    const std::string& getMobilePhone() const { return m_mobilePhone; }
    const std::string& getSignature() const { return m_signature; }
    const std::string& getGreetings() const { return m_greetings; }

  private:
    Address m_address;
    Bank m_bank;
    std::string m_phone;
    std::string m_mobilePhone;
    std::string m_signature;
    std::string m_greetings;
};

} // End namespace domain
} // End namespace nina

#endif  // NINA_DOMAIN_SENDER_H
