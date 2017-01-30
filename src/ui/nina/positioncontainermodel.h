#ifndef POSITIONCONTAINERMODEL_H
#define POSITIONCONTAINERMODEL_H

// Qt includes
#include <QAbstractTableModel>
#include <QVector>
#include <QPointer>

// Nina domain includes
#include <nina/PositionContainer.h>

// Fwd declarations
class PositionModel;



class PositionContainerModel: public QAbstractTableModel
{
    Q_OBJECT

  public:
    enum class Role {
        Description = Qt::UserRole,
        Unit,
        NumUnits,
        PricePerUnit
    };

  public:
    PositionContainerModel(QObject* parent = 0);

  public:
    nina::domain::PositionContainer createDomain() const;

  public:
    QHash<int, QByteArray> roleNames() const;
    int columnCount(const QModelIndex& /*parent*/) const { return 4; }
    int rowCount(const QModelIndex& /*parnet*/) const { return m_positions.size(); }
    QVariant data(const QModelIndex& index, int role) const;
    bool setData(const QModelIndex& index, const QVariant&  value, int role);
    Qt::ItemFlags flags(const QModelIndex& index) const;
    bool insertRows(int row, int count, const QModelIndex& parent);
    bool removeRows(int row, int count, const QModelIndex& parent);

    Q_INVOKABLE void append(const QString& description, const QString& unit, float numUnits, float pricePerUnit);
    Q_INVOKABLE PositionModel* getRow(unsigned row) const;
    Q_INVOKABLE bool setRow(unsigned row, const QString& description, const QString& unit, float numUnits, float pricePerUnit);
    Q_INVOKABLE void removeRow(unsigned row);

  private:
    bool doSetRow(unsigned row, const QString& description, const QString& unit, float numUnits, float pricePerUnit);

  private:
    QVector<QPointer<PositionModel>> m_positions;
};

#endif // POSITIONCONTAINERMODEL_H
