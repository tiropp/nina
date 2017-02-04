#ifndef FILEDIALOGBASE_H
#define FILEDIALOGBASE_H

// Qt includes
#include <QObject>
#include <QString>
#include <QList>



class FileDialogBase: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle)
    Q_PROPERTY(QString folder READ folder WRITE setFolder)
    Q_PROPERTY(QList<QString> nameFilters READ nameFilters WRITE setNameFilters)
    Q_PROPERTY(QString fileUrl READ fileUrl WRITE setFileUrl)

  public:
    FileDialogBase() {}

  public:
    void setTitle(const QString& title) { m_title = title; }
    void setFolder(const QString& folder) { m_folder = folder; }
    void setNameFilters(const QList<QString>& filters) { m_nameFilters = filters; }
    void setFileUrl(const QString& url) { m_fileUrl = url; }

  public:
    QString title() const { return m_title; }
    QString folder() const { return m_folder; }
    QList<QString> nameFilters() const { return m_nameFilters; }
    QString fileUrl() const { return m_fileUrl; }

  signals:
    void accepted();
    void rejected();

  protected:
    QString getNameFiltersString() const;

  private:
    QString m_title;
    QString m_folder;
    QList<QString> m_nameFilters;
    QString m_fileUrl;
};


#endif  // FILEDIALOGBASE_H
