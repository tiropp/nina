#include "miscmodel.h"

// Nina includes
#include <detail/macros.h>
#include <detail/conversion.h>



MiscModel::MiscModel()
{
}

nina::domain::Misc
MiscModel::createDomain() const
{
    nina::domain::Misc misc;
    misc.setTitle( toString(m_title) );
    misc.setTextAfterPositions( toString(m_textAfterPositions) );
    misc.setTextBeforePositions( toString(m_textBeforePositions) );
    return misc;
}

void
MiscModel::set(const nina::domain::Misc& misc)
{
    setTitle              ( QString::fromStdString(misc.getTitle()) );
    setTextBeforePositions( QString::fromStdString(misc.getTextBeforePositions()) );
    setTextAfterPositions ( QString::fromStdString(misc.getTextAfterPositions ()) );
}

NINA_SETPROPERTY(MiscModel, setTitle,               const QString&, title)
NINA_SETPROPERTY(MiscModel, setTextBeforePositions, const QString&, textBeforePositions)
NINA_SETPROPERTY(MiscModel, setTextAfterPositions,  const QString&, textAfterPositions)
