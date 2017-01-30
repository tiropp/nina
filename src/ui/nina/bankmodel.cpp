#include "bankmodel.h"

// Nina includes
#include <conversion.h>



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
