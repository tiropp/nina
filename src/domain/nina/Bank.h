#ifndef NINA_DOMAIN_BANK_H
#define NINA_DOMAIN_BANK_H

// STL includes
#include <string>

// BOOST includes
#include <boost/serialization/access.hpp>

// Nina includes
#include <nina/detail/SerializationHelper.h>



namespace nina {
namespace domain {

class Bank
{
  public:
    Bank() {}
    Bank(const std::string& name,
         const std::string& bic,
         const std::string& account
        )
        : m_name( name )
        , m_bic( bic )
        , m_account( account )
    {}

  public:
    void setName(const std::string& name) { m_name = name; }
    void setBic(const std::string& bic) { m_bic = bic; }
    void setAccount(const std::string& account) { m_account = account; }

  public:
    bool isValid() const;
    const std::string& getName() const { return m_name; }
    const std::string& getBic() const { return m_bic; }
    const std::string& getAccount() const { return m_account; }

  private:
    friend class boost::serialization::access;
    template<class Archive> void serialize(Archive& ar, const unsigned /*version*/) {
        NINA_SERIALIZE(ar, name);
        NINA_SERIALIZE(ar, bic);
        NINA_SERIALIZE(ar, account);
    }

  private:
    std::string m_name;
    std::string m_bic;
    std::string m_account;
};

} // End namespace domain
} // End namespace nina

#endif  // NINA_DOMAIN_BANK_H
