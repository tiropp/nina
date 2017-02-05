#include "Money.h"

// STL includes
#include <sstream>
#include <iomanip>
#include <cmath>



namespace nina {
namespace domain {

Money::Money()
    : m_money( 0 )
{
}

Money::Money(double money)
    : m_money( money )
{
}

Money::Money(const Money& other)
    : m_money( other.m_money )
{
}

Money&
Money::operator=(const Money& other)
{
    m_money = other.m_money;
    return *this;
}

Money&
Money::operator+=(const Money& other)
{
    m_money += other.m_money;
    return *this;
}

Money&
Money::operator-=(const Money& other)
{
    m_money -= other.m_money;
    return *this;
}

Money&
Money::operator*=(double factor)
{
    m_money *= factor;
    return *this;
}

Money&
Money::operator/=(double factor)
{
    m_money /= factor;
    return *this;
}

bool
Money::operator==(const Money& other) const
{
    return m_money == other.m_money;
}

bool
Money::operator!=(const Money& other) const
{
    return !operator==(other);
}

Money
Money::round(double precision, unsigned digits) const
{
    const double rounded = std::round(m_money / precision) * precision;

    const double factor = std::pow(10, digits);
    const double roundedAndTruncated = std::trunc( rounded * factor ) / factor;

    return Money( roundedAndTruncated );
}

Money
Money::roundMistake(double precision, unsigned digits) const
{
    return round(precision, digits) - *this;
}

std::string
Money::toString(double precision, unsigned digits) const
{
    std::stringstream ss;
    ss << std::setprecision(digits) << std::fixed
       << round(precision, digits).toDouble();
    return ss.str();
}

Money
operator+(const Money& lhs, const Money& rhs)
{
    Money result( lhs );
    result += rhs;
    return result;
}

Money
operator-(const Money& lhs, const Money& rhs)
{
    Money result( lhs );
    result -= rhs;
    return result;
}

Money
operator*(const Money& money, double factor)
{
    Money result( money );
    result *= factor;
    return result;
}

Money
operator/(const Money& money, double factor)
{
    Money result( money );
    result /= factor;
    return result;
}



} // End namespace domain
} // End namespace nina
