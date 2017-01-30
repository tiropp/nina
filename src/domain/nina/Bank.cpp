#include "Bank.h"


namespace nina {
namespace domain {

bool
Bank::isValid() const
{
    if( !m_name.empty() )
        return true;

    return false;
}

} // End namespace domain
} // End namespace nina
