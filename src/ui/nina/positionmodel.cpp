#include "positionmodel.h"

// Nina includes
#include <detail/conversion.h>
#include <detail/macros.h>



PositionModel::~PositionModel()
{
}

nina::domain::Position
PositionModel::createDomain() const
{
    return nina::domain::Position(toString(m_description),
                                  toString(m_unit),
                                  nina::domain::Money(m_pricePerUnit),
                                  m_numUnits);
}


NINA_SETPROPERTY(PositionModel, setDescription,  const QString&, description)
NINA_SETPROPERTY(PositionModel, setUnit,         const QString&, unit)
NINA_SETPROPERTY(PositionModel, setNumUnits,     double,         numUnits)
NINA_SETPROPERTY(PositionModel, setPricePerUnit, double,         pricePerUnit)
