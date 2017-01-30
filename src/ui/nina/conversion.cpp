#include "conversion.h"

// Qt includes
#include <QString>



std::string
toString(const QString& string)
{
    return string.toUtf8().constData();
}
