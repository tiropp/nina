#include "settingsmodel.h"

// Nina includes
#include <detail/macros.h>



SettingsModel::SettingsModel()
    : m_isPhoneInBottomField( false )
    , m_fontSize( 12 )
    , m_fontSkip( 12 )
    , m_positionSkip( 12 )
{
}

nina::domain::Settings
SettingsModel::createDomain() const
{
    nina::domain::Settings settings;
    settings.setIsPhoneInBottomField( m_isPhoneInBottomField );
    settings.setFontSize( m_fontSize );
    settings.setFontSkip( m_fontSkip );
    settings.setPositionSkip( m_positionSkip );
    return settings;
}

void
SettingsModel::set(const nina::domain::Settings& settings)
{
    setIsPhoneInBottomField( settings.isPhoneInBottomField() );
    setFontSize            ( settings.getFontSize()          );
    setFontSkip            ( settings.getFontSkip()          );
    setPositionSkip        ( settings.getPositionSkip()      );
}

NINA_SETPROPERTY(SettingsModel, setIsPhoneInBottomField, bool,     isPhoneInBottomField)
NINA_SETPROPERTY(SettingsModel, setFontSize            , unsigned, fontSize)
NINA_SETPROPERTY(SettingsModel, setFontSkip            , unsigned, fontSkip)
NINA_SETPROPERTY(SettingsModel, setPositionSkip        , unsigned, positionSkip)
