#ifndef NINA_DOMAIN_BANK_H
#define NINA_DOMAIN_BANK_H

// STL includes
#include <string>



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
    const std::string& GetName() const { return m_name; }
    const std::string& GetBIC() const { return m_bic; }
    const std::string& GetAccount() const { return m_account; }

  private:
    std::string m_name;
    std::string m_bic;
    std::string m_account;
};

} // End namespace domain
} // End namespace nina

#endif  // NINA_DOMAIN_BANK_H
