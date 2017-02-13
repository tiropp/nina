import QtQuick 2.4
import QtQuick.Controls 1.4


Item {
    width: 400
    height: 400
    property alias positions: positions

    TableView {
        id: positions
        anchors.fill: parent
        model: positionContainerModel

        TableViewColumn {            
            role: "description"
            title: qsTr("Beschreibung")
            width: parent.width - colUnit.width - colNumUnits.width - colPricePerUnit.width
        }
        TableViewColumn {
            id: colUnit
            role: "unit"
            title: qsTr("Art")
            width: 100
        }
        TableViewColumn {
            id: colNumUnits
            role: "numUnits"
            title: qsTr("Anzahl")
            width: 100
        }
        TableViewColumn {
            id: colPricePerUnit
            role: "pricePerUnit"
            title: qsTr("Fr./Art")
            width: 100
        }
    }

    signal onDoubleClicked
}
