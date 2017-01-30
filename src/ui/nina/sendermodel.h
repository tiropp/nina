#ifndef SENDERMODEL_H
#define SENDERMODEL_H

// Qt includes
#include <QObject>
#include <QString>
#include <QPointer>

// Nina domain includes
#include <nina/Sender.h>

// Nina includes
#include <addressmodel.h>
#include <bankmodel.h>



class SenderModel: public QObject
{
    Q_OBJECT
    Q_PROPERTY(AddressModel* address READ address WRITE setAddress NOTIFY addressChanged)
    Q_PROPERTY(BankModel* bank READ bank WRITE setBank NOTIFY bankChanged)
    Q_PROPERTY(QString phone READ phone WRITE setPhone NOTIFY phoneChanged)
    Q_PROPERTY(QString mobilePhone READ mobilePhone WRITE setMobilePhone NOTIFY mobilePhoneChanged)
    Q_PROPERTY(QString signature READ signature WRITE setSignature NOTIFY signatureChanged)
    Q_PROPERTY(QString greetings READ greetings WRITE setGreetings NOTIFY greetingsChanged)

  public:
    SenderModel();

  public:
    nina::domain::Sender createDomain() const;

  public:
    void setAddress(AddressModel* address) { m_address = address; }
    void setBank(BankModel* bank) { m_bank = bank; }
    void setPhone(const QString& phone) { m_phone = phone; }
    void setMobilePhone(const QString& mobilePhone) { m_mobilePhone = mobilePhone; }
    void setSignature(const QString& signature) { m_signature = signature; }
    void setGreetings(const QString& greetings) { m_greetings = greetings; }

  public:
    AddressModel* address() const { return m_address; }
    BankModel* bank() const { return m_bank; }
    QString phone() const { return m_phone; }
    QString mobilePhone() const { return m_mobilePhone; }
    QString signature() const { return m_signature; }
    QString greetings() const { return m_greetings; }

  signals:
    void addressChanged();
    void bankChanged();
    void phoneChanged();
    void mobilePhoneChanged();
    void signatureChanged();
    void greetingsChanged();

  private:
    QPointer<AddressModel> m_address;
    QPointer<BankModel> m_bank;
    QString m_phone;
    QString m_mobilePhone;
    QString m_signature;
    QString m_greetings;
};

#endif // SENDERMODEL_H
