#include "datemodel.h"


DateModel::DateModel()
    : m_useDateToday( true )
    , m_useDateSpecified( false )
    , m_day( 0 )
    , m_month( 0 )
    , m_year( 0 )
{
}

nina::domain::Date
DateModel::createDomain() const
{
    if( m_useDateToday )
        return nina::domain::Date();

    if( m_useDateSpecified )
        return nina::domain::Date(m_day, m_month, m_year);

    return nina::domain::Date();
}
