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
    Q_PROPERTY(QString account READ account WRITE setAccount NOTIFY accountChanged)
    Q_PROPERTY(QString bic READ bic WRITE setBic NOTIFY bicChanged)
    Q_PROPERTY(QString iban READ iban WRITE setIban NOTIFY ibanChanged)

  public:
    BankModel() {}
    BankModel(const BankModel& other);

  public:
    nina::domain::Bank createDomain() const;

  public:
    void set(const nina::domain::Bank& bank);
    void setName(const QString& name);
    void setAccount(const QString& account);
    void setBic(const QString& bic);
    void setIban(const QString& iban);

  public:
    QString name() const { return m_name; }
    QString account() const { return m_account; }
    QString bic() const { return m_bic; }
    QString iban() const { return m_iban; }

  signals:
    void nameChanged();
    void accountChanged();
    void bicChanged();
    void ibanChanged();

  private:
    QString m_name;
    QString m_account;
    QString m_bic;
    QString m_iban;
};

#endif // BANKMODEL_H
