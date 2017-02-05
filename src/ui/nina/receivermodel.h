#ifndef RECEIVERMODEL_H
#define RECEIVERMODEL_H

// Qt includes
#include <QObject>
#include <QString>
#include <QPointer>

// Nina domain includes
#include <nina/Receiver.h>

// Nina includes
#include <addressmodel.h>



class ReceiverModel: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString salutation READ salutation WRITE setSalutation NOTIFY salutationChanged)
    Q_PROPERTY(AddressModel* address READ address WRITE setAddress NOTIFY addressChanged)

  public:
    ReceiverModel();

  public:
    nina::domain::Receiver createDomain() const;

  public:
    void set(const nina::domain::Receiver& receiver);
    void setSalutation(const QString& salutation);
    void setAddress(AddressModel* address);

  public:
    QString salutation() const { return m_salutation; }
    AddressModel* address() const { return m_address; }

  signals:
    void salutationChanged();
    void addressChanged();

  private:
    QString m_salutation;
    QPointer<AddressModel> m_address;
};

#endif // RECEIVERMODEL_H
