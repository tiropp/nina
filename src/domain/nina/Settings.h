#ifndef NINA_DOMAIN_SETTINGS_H
#define NINA_DOMAIN_SETTINGS_H

// STL includes
#include <cstddef>



namespace nina {
namespace domain {

class Settings
{
  public:
    Settings()
        : m_isPhoneInBottomField( false )
        , m_fontSize( 12 )
        , m_fontSkip( 12 )
        , m_positionSkip( 0 )
    {}

  public:
    void setIsPhoneInBottomField(bool boolean) { m_isPhoneInBottomField = boolean; }
    void setFontSize(size_t size) { m_fontSize = size; }
    void setFontSkip(size_t size) { m_fontSkip = size; }
    void setPositionSkip(size_t posSkip) { m_positionSkip = posSkip; }

  public:
    bool isPhoneInBottomField() const { return m_isPhoneInBottomField; }
    size_t getFontSize() const { return m_fontSize; }
    size_t getFontSkip() const { return m_fontSkip; }
    size_t getPositionSkip() const { return m_positionSkip; }

  private:
    bool m_isPhoneInBottomField;
    size_t m_fontSize;
    size_t m_fontSkip;
    size_t m_positionSkip;
};

} // End namespace domain
} // End namespace nina

#endif  // NINA_DOMAIN_SETTINGS_H
