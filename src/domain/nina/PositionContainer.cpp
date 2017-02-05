#include "PositionContainer.h"


namespace nina {
namespace domain {


Money
PositionContainer::getPrice(double precision, unsigned digits) const
{
    Money price;
    for(const Position& p : m_positions)
        price += p.getPrice().round(precision, digits);

    return price;
}

} // End namespace domain
} // End namespace nina
