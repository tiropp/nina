#include "addressmodel.h"

// Nina includes
#include <detail/conversion.h>
#include <detail/macros.h>



AddressModel::AddressModel()
    : m_zipCode( 0 )
    , m_usePoBox( false )
{
}

nina::domain::Address
AddressModel::createDomain() const
{
    nina::domain::Address address;
    address.setName      ( toString(m_name) );
    address.setCompany   ( toString(m_company) );
    address.setStreet    ( toString(m_street) );
    address.setZipCode   ( m_zipCode );
    address.setPlace     ( toString(m_place) );
    address.setCountry   ( toString(m_country) );
    address.setUsePoBox  ( m_usePoBox );
    return address;
}

void
AddressModel::set(const nina::domain::Address& address)
{
    setName      ( QString::fromStdString(address.getName      ()) );
    setCompany   ( QString::fromStdString(address.getCompany   ()) );
    setStreet    ( QString::fromStdString(address.getStreet    ()) );
    setZipCode   ( address.getZipCode() );
    setPlace     ( QString::fromStdString(address.getPlace     ()) );
    setCountry   ( QString::fromStdString(address.getCountry   ()) );
    setUsePoBox  ( address.usePoBox() );
}

NINA_SETPROPERTY(AddressModel, setName      , const QString&, name)
NINA_SETPROPERTY(AddressModel, setCompany   , const QString&, company)
NINA_SETPROPERTY(AddressModel, setStreet    , const QString&, street)
NINA_SETPROPERTY(AddressModel, setZipCode   , unsigned,       zipCode)
NINA_SETPROPERTY(AddressModel, setPlace     , const QString&, place)
NINA_SETPROPERTY(AddressModel, setCountry   , const QString&, country)
NINA_SETPROPERTY(AddressModel, setUsePoBox  , bool,           usePoBox)
