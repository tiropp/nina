#ifndef SETTINGSMODEL_H
#define SETTINGSMODEL_H

// Qt includes
#include <QObject>

// Nina domain includes
#include <nina/Settings.h>



class SettingsModel: public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isPhoneInBottomField READ isPhoneInBottomField WRITE setIsPhoneInBottomField NOTIFY isPhoneInBottomFieldChanged)
    Q_PROPERTY(unsigned fontSize READ fontSize WRITE setFontSize NOTIFY fontSizeChanged)
    Q_PROPERTY(unsigned fontSkip READ fontSkip WRITE setFontSkip NOTIFY fontSkipChanged)
    Q_PROPERTY(unsigned positionSkip READ positionSkip WRITE setPositionSkip NOTIFY positionSkipChanged)

  public:
    SettingsModel();

  public:
    nina::domain::Settings createDomain() const;

  public:
    void setIsPhoneInBottomField(bool boolean) { m_isPhoneInBottomField = boolean; }
    void setFontSize(unsigned size) { m_fontSize = size; }
    void setFontSkip(unsigned size) { m_fontSkip = size; }
    void setPositionSkip(unsigned posSkip) { m_positionSkip = posSkip; }

  public:
    bool isPhoneInBottomField() const { return m_isPhoneInBottomField; }
    unsigned fontSize() const { return m_fontSize; }
    unsigned fontSkip() const { return m_fontSkip; }
    unsigned positionSkip() const { return m_positionSkip; }

  signals:
    void isPhoneInBottomFieldChanged();
    void fontSizeChanged();
    void fontSkipChanged();
    void positionSkipChanged();

  private:
    bool m_isPhoneInBottomField;
    unsigned m_fontSize;
    unsigned m_fontSkip;
    unsigned m_positionSkip;
};

#endif // SETTINGSMODEL_H
