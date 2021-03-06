#include "positioncontainermodel.h"

// Qt includes
#include <QQmlEngine>

// Nina includes
#include <positionmodel.h>



PositionContainerModel::PositionContainerModel(QObject *parent)
    : QAbstractListModel( parent )
{
}

PositionContainerModel::~PositionContainerModel()
{
}

nina::domain::PositionContainer
PositionContainerModel::createDomain() const
{
    nina::domain::PositionContainer c;
    Q_FOREACH(const auto& p, m_positions)
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
    case 2: pos->setNumUnits    ( value.toDouble()  ); break;
    case 3: pos->setPricePerUnit( value.toDouble()  ); break;
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

    return QAbstractListModel::flags(index) | Qt::ItemIsEnabled;
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
PositionContainerModel::append(const QString& description, const QString& unit, double numUnits, double pricePerUnit)
{
    size_t idx = m_positions.size();
    insert(idx, description, unit, numUnits, pricePerUnit);
}

void
PositionContainerModel::insert(unsigned row, const QString& description, const QString& unit, double numUnits, double pricePerUnit)
{
    insertRows(row, 1, QModelIndex());
    if( !doSetRow(row, description, unit, numUnits, pricePerUnit) )
        return;
    emit appended();
}

PositionModel*
PositionContainerModel::getRow(unsigned row) const
{
    position_model_ptr r = m_positions.at( row );

    // We need to tell the "system" that this pointer is owned by this class,
    // otherwise js may take ownership and at some point may delete it.
    //
    // See [1] for why this is needed in this particular case
    //
    // [1] http://doc.qt.io/qt-5/qqmlengine.html#ObjectOwnership-enum
    QQmlEngine::setObjectOwnership(r, QQmlEngine::CppOwnership);

    return r;
}

bool
PositionContainerModel::setRow(unsigned row, const QString &description, const QString &unit, double numUnits, double pricePerUnit)
{
    if( !doSetRow(row, description, unit, numUnits, pricePerUnit) )
        return false;
    dataChanged(createIndex(row, 0), createIndex(row, 0));
    return true;
}

bool
PositionContainerModel::doSetRow(unsigned row, const QString& description, const QString& unit, double numUnits, double pricePerUnit)
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

void
PositionContainerModel::clear()
{
    removeRows(0, m_positions.size(), QModelIndex());
}

void
PositionContainerModel::set(const nina::domain::PositionContainer& positions)
{
    clear();
    for(auto& position : positions)
        append(QString::fromStdString(position.getDescription()),
               QString::fromStdString(position.getUnit()),
               position.getNumUnits(),
               position.getPricePerUnit().toDouble()
            );
}

void
PositionContainerModel::refresh()
{
    dataChanged(createIndex(0, 0),
                createIndex(m_positions.size(), 0));
}
