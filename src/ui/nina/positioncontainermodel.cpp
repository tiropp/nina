#include "positioncontainermodel.h"

// Nina includes
#include <positionmodel.h>



PositionContainerModel::PositionContainerModel(QObject *parent)
    : QAbstractTableModel( parent )
{
}

nina::domain::PositionContainer
PositionContainerModel::createDomain() const
{
    nina::domain::PositionContainer c;
    Q_FOREACH(const QPointer<PositionModel>& p, m_positions)
        c.add( p->createDomain() );
    return c;
}

QHash<int, QByteArray>
PositionContainerModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[static_cast<int>(Role::Description)]  = "description";
    roles[static_cast<int>(Role::Unit)]         = "unit";
    roles[static_cast<int>(Role::NumUnits)]     = "numUnits";
    roles[static_cast<int>(Role::PricePerUnit)] = "pricePerUnit";
    return roles;
}

QVariant
PositionContainerModel::data(const QModelIndex& index, int role) const
{
    if( !index.isValid() )
        return QVariant();

    const auto& pos = m_positions.at( index.row() );
    switch( static_cast<Role>(role) ) {
    case Role::Description:  return QVariant( pos->description() );
    case Role::Unit:         return QVariant( pos->unit() );
    case Role::NumUnits:     return QVariant( pos->numUnits() );
    case Role::PricePerUnit: return QVariant( pos->pricePerUnit() );
    default:                 return QVariant();
    }
}

bool
PositionContainerModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if( !index.isValid() || role != Qt::EditRole )
        return false;

    auto& pos = m_positions.at( index.row() );
    switch( index.column() ) {
    case 0: pos->setDescription ( value.toString() ); break;
    case 1: pos->setUnit        ( value.toString() ); break;
    case 2: pos->setNumUnits    ( value.toFloat()  ); break;
    case 3: pos->setPricePerUnit( value.toFloat()  ); break;
    default:
        return false;
    }

    emit dataChanged(index, index);
    return true;
}

Qt::ItemFlags
PositionContainerModel::flags(const QModelIndex& index) const
{
    if( !index.isValid() )
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEnabled;
}

bool
PositionContainerModel::insertRows(int row, int count, const QModelIndex& parent)
{
    if( count < 1  || row < 0 || row > rowCount(parent) )
        return false;

    beginInsertRows(QModelIndex(), row, row + count -1);
    for(int r = 0; r < count; ++r)
        m_positions.insert(row, new PositionModel());
    endInsertRows();

    return 0;
}

bool
PositionContainerModel::removeRows(int row, int count, const QModelIndex& parent)
{
    if( count <= 0 || row < 0 || (row + count) > rowCount(parent))
        return false;

    beginRemoveRows(QModelIndex(), row, row + count - 1);
    m_positions.remove(row, count);
    endRemoveRows();

    return true;
}

void
PositionContainerModel::append(const QString& description, const QString& unit, float numUnits, float pricePerUnit)
{
    size_t idx = m_positions.size();
    insertRows(idx, 1, QModelIndex());
    doSetRow(idx, description, unit, numUnits, pricePerUnit);
}

PositionModel*
PositionContainerModel::getRow(unsigned row) const
{
    return m_positions.at( row );
}

bool
PositionContainerModel::setRow(unsigned row, const QString &description, const QString &unit, float numUnits, float pricePerUnit)
{
    if( !doSetRow(row, description, unit, numUnits, pricePerUnit) )
        return false;
    dataChanged(createIndex(row, 0), createIndex(row, 0));
    return true;
}

bool
PositionContainerModel::doSetRow(unsigned row, const QString& description, const QString& unit, float numUnits, float pricePerUnit)
{
    if( static_cast<int>(row) >= m_positions.size() )
        return false;

    auto& pos = m_positions[row];
    pos->setDescription( description );
    pos->setUnit( unit );
    pos->setNumUnits( numUnits );
    pos->setPricePerUnit( pricePerUnit );

    return true;
}

void
PositionContainerModel::removeRow(unsigned row)
{
    removeRows(row, 1, QModelIndex());
}
