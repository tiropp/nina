#include "Vat.h"


namespace nina {
namespace domain {

Vat::Vat()
    : m_showVat( false )
    , m_pricesInclVat( false )
    , m_taxRate( 0 )
{
}

Vat::Vat(bool pricesInclVat, const std::string& vatNumber, double taxRate)
    : m_showVat( true )
    , m_pricesInclVat( pricesInclVat )
    , m_vatNumber( vatNumber )
    , m_taxRate( taxRate )
{
}

} // End namespace domain
} // End namespace nina
