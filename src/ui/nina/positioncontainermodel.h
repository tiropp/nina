#ifndef POSITIONCONTAINERMODEL_H
#define POSITIONCONTAINERMODEL_H

// Qt includes
#include <QAbstractListModel>
#include <QVector>
#include <QPointer>

// Nina domain includes
#include <nina/PositionContainer.h>

// Fwd declarations
class PositionModel;



class PositionContainerModel: public QAbstractListModel
{
    Q_OBJECT


    /*************/
    /*** TYPES ***/
    /*************/
  public:
    enum class Role {
        Description = Qt::UserRole,
        Unit,
        NumUnits,
        PricePerUnit
    };


    /******************/
    /*** CTOR, DTOR ***/
    /******************/
  public:
    PositionContainerModel(QObject* parent = 0);
    ~PositionContainerModel();

    /***************/
    /*** DOMAIN  ***/
    /***************/
  public:
    nina::domain::PositionContainer createDomain() const;
    void set(const nina::domain::PositionContainer& positions);


    /******************/
    /*** OPERATIONS ***/
    /******************/
  public:
    Q_INVOKABLE void append(const QString& description, const QString& unit, double numUnits, double pricePerUnit);
    Q_INVOKABLE void insert(unsigned row, const QString& description, const QString& unit, double numUnits, double pricePerUnit);
    Q_INVOKABLE PositionModel* getRow(unsigned row) const;
    Q_INVOKABLE bool setRow(unsigned row, const QString& description, const QString& unit, double numUnits, double pricePerUnit);
    Q_INVOKABLE void removeRow(unsigned row);
    Q_INVOKABLE void clear();
    Q_INVOKABLE void refresh();


    /****************************************************/
    /*** QAbstractListModel INTERFACE IMPLEMENTATIONS ***/
    /****************************************************/
  public:
    virtual QHash<int, QByteArray> roleNames() const override;
    virtual int rowCount(const QModelIndex& /*parnet*/) const { return m_positions.size(); }
    virtual QVariant data(const QModelIndex& index, int role) const override;
    virtual bool setData(const QModelIndex& index, const QVariant&  value, int role) override;
    virtual Qt::ItemFlags flags(const QModelIndex& index) const override;
    virtual bool insertRows(int row, int count, const QModelIndex& parent) override;
    virtual bool removeRows(int row, int count, const QModelIndex& parent) override;


  signals:
    void appended();

  private:
    bool doSetRow(unsigned row, const QString& description, const QString& unit, double numUnits, double pricePerUnit);

  private:
    typedef QPointer<PositionModel> position_model_ptr;

  private:
    QVector<position_model_ptr> m_positions;
};

#endif // POSITIONCONTAINERMODEL_H
