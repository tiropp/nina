#include "sendermodel.h"

// Nina includes
#include <detail/conversion.h>
#include <detail/macros.h>



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
    sender.setEmail      ( toString(m_email) );
    sender.setWebpage    ( toString(m_webpage) );
    sender.setSignature  ( toString(m_signature) );
    sender.setGreetings  ( toString(m_greetings) );
    return sender;
}

void
SenderModel::set(const nina::domain::Sender& sender)
{
    m_address->set( sender.getAddress() );
    m_bank   ->set( sender.getBank()    );
    setPhone      ( QString::fromStdString(sender.getPhone()      ) );
    setMobilePhone( QString::fromStdString(sender.getMobilePhone()) );
    setEmail      ( QString::fromStdString(sender.getEmail()      ) );
    setWebpage    ( QString::fromStdString(sender.getWebpage()    ) );
    setSignature  ( QString::fromStdString(sender.getSignature()  ) );
    setGreetings  ( QString::fromStdString(sender.getGreetings()  ) );
}

NINA_SETPROPERTY(SenderModel, setAddress    , AddressModel*,  address)
NINA_SETPROPERTY(SenderModel, setBank       , BankModel*,     bank)
NINA_SETPROPERTY(SenderModel, setPhone      , const QString&, phone)
NINA_SETPROPERTY(SenderModel, setMobilePhone, const QString&, mobilePhone)
NINA_SETPROPERTY(SenderModel, setEmail      , const QString&, email)
NINA_SETPROPERTY(SenderModel, setWebpage    , const QString&, webpage)
NINA_SETPROPERTY(SenderModel, setSignature  , const QString&, signature)
NINA_SETPROPERTY(SenderModel, setGreetings  , const QString&, greetings)
