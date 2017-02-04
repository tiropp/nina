#ifndef VATMODEL_H
#define VATMODEL_H

// Qt includes
#include <QObject>

// Nina domain includes
#include <nina/Vat.h>



class VatModel: public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool showVat READ showVat WRITE setShowVat NOTIFY showVatChanged)
    Q_PROPERTY(bool pricesInclVat READ pricesInclVat WRITE setPricesInclVat NOTIFY pricesInclVatChanged)
    Q_PROPERTY(QString vatNumber READ vatNumber WRITE setVatNumber NOTIFY vatNumberChanged)
    Q_PROPERTY(double taxRate READ taxRate WRITE setTaxRate NOTIFY taxRateChanged)

  public:
    VatModel();

  public:
    nina::domain::Vat createDomain() const;

  public:
    void set(const nina::domain::Vat& vat);
    void setShowVat(bool showVat);
    void setPricesInclVat(bool pricesInclVat);
    void setVatNumber(const QString& vatNumber);
    void setTaxRate(double taxRate);

  public:
    bool showVat() const { return m_showVat; }
    bool pricesInclVat() const { return m_pricesInclVat; }
    QString vatNumber() const { return m_vatNumber; }
    double taxRate() const { return m_taxRate; }

  signals:
    void showVatChanged();
    void pricesInclVatChanged();
    void vatNumberChanged();
    void taxRateChanged();

  private:
    bool m_showVat;
    bool m_pricesInclVat;
    QString m_vatNumber;
    double m_taxRate;
};

#endif // VATMODEL_H
