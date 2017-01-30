#include "Date.h"


namespace nina {
namespace domain {

Date::Date()
    : m_useToday( true )
    , m_day( 0 )
    , m_month( 0 )
    , m_year( 0 )
{
}

Date::Date(size_t day, size_t month, size_t year)
    : m_useToday( false )
    , m_day( day )
    , m_month( month )
    , m_year( year )
{
}

std::string
Date::toString() const
{
    return
        std::to_string(m_day) + "." +
        std::to_string(m_month) + "." +
        std::to_string(m_year);
}


} // End namespace domain
} // End namespace nina
