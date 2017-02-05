#include "bankmodel.h"

// Nina includes
#include <detail/conversion.h>
#include <detail/macros.h>



BankModel::BankModel(const BankModel& other)
    : QObject()
    , m_name   ( other.m_name    )
    , m_bic    ( other.m_bic     )
    , m_account( other.m_account )
{
}

nina::domain::Bank
BankModel::createDomain() const
{
    nina::domain::Bank bank;
    bank.setName   ( toString(m_name) );
    bank.setBic    ( toString(m_bic) );
    bank.setAccount( toString(m_account) );
    return bank;
}

void
BankModel::set(const nina::domain::Bank& bank)
{
    setName   ( QString::fromStdString(bank.getName()) );
    setBic    ( QString::fromStdString(bank.getBic()) );
    setAccount( QString::fromStdString(bank.getAccount()) );
}

NINA_SETPROPERTY(BankModel, setName   , const QString&, name)
NINA_SETPROPERTY(BankModel, setBic    , const QString&, bic)
NINA_SETPROPERTY(BankModel, setAccount, const QString&, account)
