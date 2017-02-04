#include "receivermodel.h"

// Nina includes
#include <detail/macros.h>



ReceiverModel::ReceiverModel()
    : m_address( new AddressModel() )
{
}

nina::domain::Receiver
ReceiverModel::createDomain() const
{
    nina::domain::Receiver receiver;
    receiver.setAddress( m_address->createDomain() );
    return receiver;
}


void
ReceiverModel::set(const nina::domain::Receiver& receiver)
{
    m_address->set( receiver.getAddress() );
}

NINA_SETPROPERTY(ReceiverModel, setAddress , AddressModel*, address)
