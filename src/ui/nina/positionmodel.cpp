#include "positionmodel.h"

// Nina includes
#include <detail/conversion.h>
#include <detail/macros.h>



nina::domain::Position
PositionModel::createDomain() const
{
    return nina::domain::Position(toString(m_description),
                                  toString(m_unit),
                                  m_numUnits,
                                  m_pricePerUnit);
}


NINA_SETPROPERTY(PositionModel, setDescription,  const QString&, description)
NINA_SETPROPERTY(PositionModel, setUnit,         const QString&, unit)
NINA_SETPROPERTY(PositionModel, setNumUnits,     float,          numUnits)
NINA_SETPROPERTY(PositionModel, setPricePerUnit, float,          pricePerUnit)
