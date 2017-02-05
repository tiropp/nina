#include "Position.h"



namespace nina {
namespace domain {


Position::Position()
    : m_numUnits( 0 )
    , m_hasOnlyDescription( false )
    , m_isFreeOfCharge( false )
    , m_isFlatPrice( false )
{
}

Position::Position(
    const std::string& description,
    const std::string& unit,
    Money              pricePerUnit,
    double             numUnits
    )
    : m_description( description )
    , m_unit( unit )
    , m_pricePerUnit( pricePerUnit )
    , m_numUnits( numUnits )
    , m_price( m_pricePerUnit * m_numUnits )
    , m_hasOnlyDescription( false )
    , m_isFreeOfCharge( false )
    , m_isFlatPrice( false )
{
}

Position::Position(
    const std::string& description,
    Money              price
    )
    : m_description( description )
    , m_numUnits( 0 )
    , m_price( price )
    , m_hasOnlyDescription( false )
    , m_isFreeOfCharge( false )
    , m_isFlatPrice( true )
{
}

Position::Position(const std::string& description, Flags flags)
    : m_description( description )
    , m_numUnits( 0 )
    , m_hasOnlyDescription( true )
    , m_isFreeOfCharge( flags & freeOfCharge )
    , m_isFlatPrice( false )
{
}

} // End namespace domain
} // End namespace nina
