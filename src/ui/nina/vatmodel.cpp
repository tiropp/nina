#include "vatmodel.h"

// Nina includes
#include <conversion.h>
#include <detail/macros.h>



VatModel::VatModel()
    : m_showVat( false )
    , m_pricesInclVat( false )
    , m_taxRate( 0 )
{
}

nina::domain::Vat
VatModel::createDomain() const
{
    if( m_showVat )
        return nina::domain::Vat(m_pricesInclVat,
                                 toString(m_vatNumber),
                                 m_taxRate);
    else
        return nina::domain::Vat();
}

void
VatModel::set(const nina::domain::Vat& vat)
{
    setShowVat      ( vat.getShowVat() );
    setPricesInclVat( vat.getPricesInclVat() );
    setVatNumber    ( QString::fromStdString(vat.getVatNumber()) );
    setTaxRate      ( vat.getTaxRate() );
}

NINA_SETPROPERTY(VatModel, setShowVat,       bool,           showVat)
NINA_SETPROPERTY(VatModel, setPricesInclVat, bool,           pricesInclVat)
NINA_SETPROPERTY(VatModel, setVatNumber,     const QString&, vatNumber)
NINA_SETPROPERTY(VatModel, setTaxRate,       double,         taxRate)
