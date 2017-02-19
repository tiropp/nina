#ifndef POSITIONMODEL_H
#define POSITIONMODEL_H

// Qt includes
#include <QObject>
#include <QString>

// Nina domain includes
#include <nina/Position.h>



class PositionModel: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QString unit READ unit WRITE setUnit NOTIFY unitChanged)
    Q_PROPERTY(double numUnits READ numUnits WRITE setNumUnits NOTIFY numUnitsChanged)
    Q_PROPERTY(double pricePerUnit READ pricePerUnit WRITE setPricePerUnit NOTIFY pricePerUnitChanged)

  public:
    PositionModel()
        : m_numUnits( 0 )
        , m_pricePerUnit( 0 )
    {}
    PositionModel(const QString& description, const QString& unit, double numUnits, double pricePerUnit)
        : m_description( description )
        , m_unit( unit )
        , m_numUnits( numUnits )
        , m_pricePerUnit( pricePerUnit )
    {}
    ~PositionModel();

  public:
    nina::domain::Position createDomain() const;

  public:
    void setDescription(const QString& description);
    void setUnit(const QString& unit);
    void setNumUnits(double numUnits);
    void setPricePerUnit(double pricePerUnit);

  public:
    QString description() const { return m_description; }
    QString unit() const { return m_unit; }
    double numUnits() const { return m_numUnits; }
    double pricePerUnit() const { return m_pricePerUnit; }

  signals:
    void descriptionChanged();
    void unitChanged();
    void numUnitsChanged();
    void pricePerUnitChanged();

  private:
    QString m_description;
    QString m_unit;
    double m_numUnits;
    double m_pricePerUnit;
};

#endif // POSITIONMODEL_H
