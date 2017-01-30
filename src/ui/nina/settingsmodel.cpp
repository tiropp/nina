#include "settingsmodel.h"


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
