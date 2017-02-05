#include "bankmodel.h"

// Nina includes
#include <detail/conversion.h>
#include <detail/macros.h>



BankModel::BankModel(const BankModel& other)
    : QObject()
    , m_name   ( other.m_name    )
    , m_account( other.m_account )
    , m_bic    ( other.m_bic     )
    , m_iban   ( other.m_iban    )
{
}

nina::domain::Bank
BankModel::createDomain() const
{
    nina::domain::Bank bank;
    bank.setName   ( toString(m_name) );
    bank.setAccount( toString(m_account) );
    bank.setBic    ( toString(m_bic) );
    bank.setIban   ( toString(m_iban) );
    return bank;
}

void
BankModel::set(const nina::domain::Bank& bank)
{
    setName   ( QString::fromStdString(bank.getName()) );
    setAccount( QString::fromStdString(bank.getAccount()) );
    setBic    ( QString::fromStdString(bank.getBic()) );
    setIban   ( QString::fromStdString(bank.getIban()) );
}

NINA_SETPROPERTY(BankModel, setName   , const QString&, name)
NINA_SETPROPERTY(BankModel, setAccount, const QString&, account)
NINA_SETPROPERTY(BankModel, setBic    , const QString&, bic)
NINA_SETPROPERTY(BankModel, setIban   , const QString&, iban)
