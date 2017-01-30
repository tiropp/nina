import QtQuick 2.4
import QtQuick.Controls 2.0

Item {
    width: 500
    height: 500
    property alias rectangle: rectangle
    property alias pricePerUnit: pricePerUnit
    property alias numUnits: numUnits
    property alias unit: unit
    property alias price: price
    property alias useFreeOfCharge: useFreeOfCharge
    property alias useFlatPrice: useFlatPrice
    property alias useStandard: useStandard
    property alias description: description
    property alias btnCancel: btnCancel
    property alias btnOK: btnOK

    Rectangle {
        id: rectangle
        color: "#ffffff"
        anchors.fill: parent

        RadioButton {
            id: useStandard
            x: 8
            y: 8
            text: qsTr("Standard")
            checked: true
        }

        RadioButton {
            id: useFlatPrice
            x: 8
            y: 49
            text: qsTr("Pauschal Betrag")
        }

        RadioButton {
            id: useFreeOfCharge
            x: 8
            y: 90
            text: qsTr("gratis")
        }

        Label {
            id: label2
            x: 8
            y: 243
            text: qsTr("Label")
            opacity: 0
        }

        Label {
            id: label1
            x: 8
            y: 205
            text: qsTr("Label")
            opacity: 0
        }

        Label {
            id: label
            x: 8
            y: 164
            text: qsTr("Label")
            opacity: 0
        }

        Label {
            id: label4
            x: 18
            y: 177
            text: qsTr("Label")
            opacity: 0
        }

        Label {
            id: label5
            x: 8
            y: 220
            text: qsTr("Label")
            opacity: 0
        }

        Label {
            id: label3
            x: 8
            y: 297
            text: qsTr("Beschreibung")
        }

        TextField {
            id: unit
            x: 80
            y: 151
            text: qsTr("Text Field")
            opacity: 0
        }

        TextField {
            id: numUnits
            x: 80
            y: 191
            text: qsTr("Text Field")
            opacity: 0
        }

        TextField {
            id: pricePerUnit
            x: 80
            y: 230
            text: qsTr("Text Field")
            opacity: 0
        }

        TextField {
            id: price
            x: 83
            y: 166
            text: qsTr("Text Field")
            opacity: 0
        }

        TextArea {
            id: description
            y: 317
            height: 125
            text: qsTr("")
            wrapMode: Text.WordWrap
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.left: parent.left
            anchors.leftMargin: 10
        }

        ToolBar {
            id: toolBar
            y: 460
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.right: parent.right
            anchors.rightMargin: 10

            Button {
                id: btnOK
                x: 380
                y: 0
                text: qsTr("OK")
                anchors.right: parent.right
                anchors.rightMargin: 0
            }

            Button {
                id: btnCancel
                x: 274
                y: 0
                text: qsTr("Abbrechen")
                anchors.right: parent.right
                anchors.rightMargin: 106
            }
        }
    }
    states: [
        State {
            name: "standard"
            when: useStandard.checked

            PropertyChanges {
                target: unit
                x: 80
                y: 146
                text: qsTr("")
                opacity: 1
            }

            PropertyChanges {
                target: numUnits
                x: 80
                y: 192
                text: qsTr("")
                opacity: 1
            }

            PropertyChanges {
                target: pricePerUnit
                x: 80
                y: 238
                text: qsTr("")
                opacity: 1
            }

            PropertyChanges {
                target: rectangle
                anchors.bottomMargin: 0
                anchors.topMargin: 0
                anchors.leftMargin: 0
                anchors.rightMargin: 0
            }

            PropertyChanges {
                target: label
                x: 8
                y: 159
                text: qsTr("Art")
                opacity: 1
            }

            PropertyChanges {
                target: label1
                x: 8
                y: 205
                text: qsTr("Anzahl")
                opacity: 1
            }

            PropertyChanges {
                target: label2
                x: 8
                y: 251
                text: qsTr("Fr./Art")
                opacity: 1
            }

            PropertyChanges {
                target: useFlatPrice
                text: qsTr("Pauschal Betrag")
            }
        },
        State {
            name: "flatPrice"
            when: useFlatPrice.checked

            PropertyChanges {
                target: price
                x: 80
                y: 237
                text: qsTr("")
                opacity: 1
            }

            PropertyChanges {
                target: label4
                x: 8
                y: 250
                text: qsTr("Betrag")
                opacity: 1
            }

            PropertyChanges {
                target: useStandard
                checked: false
            }
        },
        State {
            name: "freeOfCharge"
            when: useFreeOfCharge.checked
        }
    ]
}
