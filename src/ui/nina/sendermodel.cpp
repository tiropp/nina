#include "sendermodel.h"

// Nina includes
#include <conversion.h>



SenderModel::SenderModel()
    : m_address( new AddressModel() )
    , m_bank( new BankModel() )
{
}

nina::domain::Sender
SenderModel::createDomain() const
{
    nina::domain::Sender sender;
    sender.setAddress    ( m_address->createDomain() );
    sender.setBank       ( m_bank->createDomain() );
    sender.setPhone      ( toString(m_phone) );
    sender.setMobilePhone( toString(m_mobilePhone) );
    sender.setSignature  ( toString(m_signature) );
    sender.setGreetings  ( toString(m_greetings) );
    return sender;
}
