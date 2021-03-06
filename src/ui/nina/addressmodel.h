#ifndef ADDRESSMODEL_H
#define ADDRESSMODEL_H

// Qt includes
#include <QObject>

// Nina domain includes
#include <nina/Address.h>



class AddressModel: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString company READ company WRITE setCompany NOTIFY companyChanged)
    Q_PROPERTY(QString street READ street WRITE setStreet NOTIFY streetChanged)
    Q_PROPERTY(unsigned zipCode READ zipCode WRITE setZipCode NOTIFY zipCodeChanged)
    Q_PROPERTY(QString place READ place WRITE setPlace NOTIFY placeChanged)
    Q_PROPERTY(QString country READ country WRITE setCountry NOTIFY countryChanged)
    Q_PROPERTY(bool usePoBox READ usePoBox WRITE setUsePoBox NOTIFY usePoBoxChanged)

  public:
    AddressModel();

  public:
    nina::domain::Address createDomain() const;

  public:
    void set(const nina::domain::Address& address);
    void setName(const QString& name);
    void setCompany(const QString& company);
    void setStreet(const QString& street);
    void setZipCode(unsigned zipCode);
    void setPlace(const QString& place);
    void setCountry(const QString& country);
    void setUsePoBox(bool poBox);

  public:
    QString name() const { return m_name; }
    QString company() const { return m_company; }
    QString street() const { return m_street; }
    unsigned zipCode() const { return m_zipCode; }
    QString place() const { return m_place; }
    QString country() const { return m_country; }
    bool usePoBox() const { return m_usePoBox; }

  signals:
    void nameChanged();
    void companyChanged();
    void streetChanged();
    void zipCodeChanged();
    void placeChanged();
    void countryChanged();
    void usePoBoxChanged();

  private:
    QString m_name;
    QString m_company;
    QString m_street;
    unsigned m_zipCode;
    QString m_place;
    QString m_country;
    bool m_usePoBox;
};

#endif // ADDRESSMODEL_H
