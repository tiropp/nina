import QtQuick 2.4
import QtQuick.Controls 2.0

Item {
    id: item1
    width: 500
    height: 400
    property alias pricePerUnit: pricePerUnit
    property alias numUnits: numUnits
    property alias unit: unit
    property alias description: description

    TextField {
        id: unit
        x: 82
        y: 13
        text: qsTr("")
    }

    TextField {
        id: numUnits
        x: 82
        y: 53
        text: qsTr("")
    }

    TextField {
        id: pricePerUnit
        x: 82
        y: 92
        text: qsTr("")
    }

    TextArea {
        id: description
        x: 12
        y: 184
        height: 212
        text: qsTr("")
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        wrapMode: Text.WordWrap
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
    }

    Label {
        id: label
        x: 10
        y: 26
        text: qsTr("Art")
    }

    Label {
        id: label1
        x: 10
        y: 67
        text: qsTr("Anzahl")
    }

    Label {
        id: label2
        x: 10
        y: 105
        text: qsTr("Fr./Art")
    }

    Label {
        id: label3
        x: 10
        y: 159
        text: qsTr("Beschreibung")
    }

    Label {
        id: label4
        x: 298
        y: 13
        width: 192
        height: 70
        text: qsTr("Bemerkung:
Anzahl = *: Pauschalbetrag
Beschreibung = @: Einschub
Anzahl = g: Gratis
")
        wrapMode: Text.WordWrap
    }
}
