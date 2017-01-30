#include "PositionContainer.h"


namespace nina {
namespace domain {


size_t
PositionContainer::getPrice() const
{
    size_t price = 0;
    for(const Position& p : m_positions)
        price += p.getPrice();

    return price;
}

} // End namespace domain
} // End namespace nina
