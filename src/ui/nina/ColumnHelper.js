var columnWidths = {}

function calcColumnHeaderWidth(header, parent)
{
    setColumnWidth(parent, header, 'description')
    setColumnWidth(parent, header, 'unit')
    setColumnWidth(parent, header, 'numUnits')
    setColumnWidth(parent, header, 'pricePerUnit')
    return columnWidths
}

function calcColumnWidths(model, parent)
{
    for(var rowIndex = 0; rowIndex < model.rowCount(); ++rowIndex) {
        var row = model.getRow( rowIndex )
        setColumnWidth(parent, row, 'description')
        setColumnWidth(parent, row, 'unit')
        setColumnWidth(parent, row, 'numUnits')
        setColumnWidth(parent, row, 'pricePerUnit')
    }
    return columnWidths
}

function setColumnWidth(parent, row, key)
{
    var text = row[key]
    var width = calcWidth(parent, text)

    if( !columnWidths[key] )
        columnWidths[key] = 0
    columnWidths[key] = Math.max(width, columnWidths[key])
}

function calcWidth(parent, text)
{
    var textElement = Qt.createQmlObject(
        'import QtQuick 2.0;'
        + 'Text {'
        + ' text: "' + text + '" '
        + '}',
        parent, "ColumnHelpers::calcWidth")
    var width = textElement.width
    textElement.destroy()
    return width
}
