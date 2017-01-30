#include "receivermodel.h"



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
