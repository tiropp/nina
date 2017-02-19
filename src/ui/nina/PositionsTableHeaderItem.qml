import QtQuick 2.0
import QtQuick.Layouts 1.1


Item {
    width: parent.width - 15
    height: background.height
    property alias description: descr
    property alias unit: unit
    property alias numUnits: numUnits
    property alias pricePerUnit: pricePerUnit

    Rectangle {
        id: background
        width: parent.width + 15
        height: row.height * 1.4
        color: "#888888"
    }

    RowLayout {
        id: row
        width: parent.width
        spacing: 5
        anchors.verticalCenter: background.verticalCenter

        Item {
            width: 5
            height: 1
        }

        Text {
            id: descr
            Layout.fillWidth: true
            text: qsTr("Beschreibung")
            font.bold: true
            wrapMode: Text.WordWrap
        }
        Loader { sourceComponent: columnSeparator; height: descr.height }

        Text {
            id: unit
            width: positions.columnWidths['unit']
            Layout.minimumWidth: width
            text: qsTr("Art")
            font.bold: true
        }
        Loader { sourceComponent: columnSeparator; height: descr.height }

        Text {
            id: numUnits
            width: positions.columnWidths['numUnits']
            Layout.minimumWidth: width
            text: qsTr("Anzahl")
            font.bold: true
        }
        Loader { sourceComponent: columnSeparator; height: descr.height }

        Text {
            id: pricePerUnit
            width: positions.columnWidths['pricePerUnit']
            Layout.minimumWidth: width
            text: qsTr("Fr./Art")
            font.bold: true
        }

        Component {
            id: columnSeparator
            Rectangle {
                width: 1
                color: "black"
                opacity: 0.3
            }
         }
    }
}

