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
    Q_PROPERTY(AddressModel* address READ address WRITE setAddress NOTIFY addressChanged)

  public:
    ReceiverModel();

  public:
    nina::domain::Receiver createDomain() const;

  public:
    void setAddress(AddressModel* address) { m_address = address; }

  public:
    AddressModel* address() const { return m_address; }

  signals:
    void addressChanged();

  private:
    QPointer<AddressModel> m_address;
};

#endif // RECEIVERMODEL_H
