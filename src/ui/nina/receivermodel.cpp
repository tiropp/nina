#include "receivermodel.h"

// Nina includes
#include <detail/conversion.h>
#include <detail/macros.h>



ReceiverModel::ReceiverModel()
    : m_address( new AddressModel() )
{
}

nina::domain::Receiver
ReceiverModel::createDomain() const
{
    nina::domain::Receiver receiver;
    receiver.setSalutation( toString(m_salutation) );
    receiver.setAddress   ( m_address->createDomain() );
    return receiver;
}


void
ReceiverModel::set(const nina::domain::Receiver& receiver)
{
    setSalutation( QString::fromStdString(receiver.getSalutation()) );
    m_address->set( receiver.getAddress() );
}

NINA_SETPROPERTY(ReceiverModel, setSalutation, const QString&, salutation)
NINA_SETPROPERTY(ReceiverModel, setAddress , AddressModel*, address)
