#include "addressmodel.h"

// Nina includes
#include <conversion.h>



AddressModel::AddressModel()
    : m_zipCode( 0 )
    , m_usePoBox( false )
{
}

nina::domain::Address
AddressModel::createDomain() const
{
    nina::domain::Address address;
    address.setSalutation( toString(m_salutation) );
    address.setName      ( toString(m_name) );
    address.setCompany   ( toString(m_company) );
    address.setStreet    ( toString(m_street) );
    address.setZipCode   ( m_zipCode );
    address.setPlace     ( toString(m_place) );
    address.setCountry   ( toString(m_country) );
    address.setUsePoBox  ( m_usePoBox );
    return address;
}
