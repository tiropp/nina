#include "datemodel.h"

// Nina includes
#include <detail/macros.h>



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

void
DateModel::set(const nina::domain::Date& date)
{
    if( date.useToday() ) {
        setUseDateToday( true );
        setUseDateSpecified( false );
        setDay  ( 0 );
        setMonth( 0 );
        setYear ( 0 );
    }
    else {
        setUseDateToday( false );
        setUseDateSpecified( true );
        setDay  ( date.getDay() );
        setMonth( date.getMonth() );
        setYear ( date.getYear() );
    }
}

NINA_SETPROPERTY(DateModel, setUseDateToday    , bool,     useDateToday)
NINA_SETPROPERTY(DateModel, setUseDateSpecified, bool,     useDateSpecified)
NINA_SETPROPERTY(DateModel, setDay             , unsigned, day)
NINA_SETPROPERTY(DateModel, setMonth           , unsigned, month)
NINA_SETPROPERTY(DateModel, setYear            , unsigned, year)
