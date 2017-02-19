#ifndef MISCMODEL_H
#define MISCMODEL_H

// Qt includes
#include <QObject>

// Nina domain includes
#include <nina/Misc.h>



class MiscModel: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString textBeforePositions READ textBeforePositions WRITE setTextBeforePositions NOTIFY textBeforePositionsChanged)
    Q_PROPERTY(QString textAfterPositions READ textAfterPositions WRITE setTextAfterPositions NOTIFY textAfterPositionsChanged)

  public:
    MiscModel();

  public:
    nina::domain::Misc createDomain() const;

  public:
    QString title() const { return m_title; }
    QString textBeforePositions() const { return m_textBeforePositions; }
    QString textAfterPositions() const { return m_textAfterPositions; }

  public:
    void set(const nina::domain::Misc& misc);
    void setTitle(const QString& title);
    void setTextBeforePositions(const QString& text);
    void setTextAfterPositions(const QString& text);

  signals:
    void titleChanged();
    void textBeforePositionsChanged();
    void textAfterPositionsChanged();

  private:
    QString m_title;
    QString m_textBeforePositions;
    QString m_textAfterPositions;
};

#endif // MISCMODEL_H
