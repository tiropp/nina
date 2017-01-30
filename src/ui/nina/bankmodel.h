#ifndef BANKMODEL_H
#define BANKMODEL_H

// Qt includes
#include <QObject>
#include <QString>

// Nina domain includes
#include <nina/Bank.h>



class BankModel: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString bic READ bic WRITE setBic NOTIFY bicChanged)
    Q_PROPERTY(QString account READ account WRITE setAccount NOTIFY accountChanged)

  public:
    BankModel() {}
    BankModel(const BankModel& other);

  public:
    nina::domain::Bank createDomain() const;

  public:
    void setName(const QString& name) { m_name = name; }
    void setBic(const QString& bic) { m_bic = bic; }
    void setAccount(const QString& account) { m_account = account; }

  public:
    QString name() const { return m_name; }
    QString bic() const { return m_bic; }
    QString account() const { return m_account; }

  signals:
    void nameChanged();
    void bicChanged();
    void accountChanged();

  private:
    QString m_name;
    QString m_bic;
    QString m_account;
};

#endif // BANKMODEL_H
