#include "positionmodel.h"

// Nina includes
#include <conversion.h>



nina::domain::Position
PositionModel::createDomain() const
{
    return nina::domain::Position(toString(m_description),
                                  toString(m_unit),
                                  m_numUnits,
                                  m_pricePerUnit);
}
