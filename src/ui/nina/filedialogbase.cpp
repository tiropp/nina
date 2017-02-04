#include "filedialogbase.h"


QString
FileDialogBase::getNameFiltersString() const
{
    QString result;
    Q_FOREACH(const auto& filter, m_nameFilters) {
        if( !result.isEmpty() )
            result += ";;";
        result += filter;
    }
    return result;
}
