import QtQuick 2.4
import QtQuick.Controls 2.0

Item {
    id: root
    width: childrenRect.width
    height: childrenRect.height
    property alias show: show
    property alias taxRate: taxRate
    property alias number: number
    property alias pricesInclVat: pricesInclVat
    property alias pricesExclVat: pricesExclVat
    property alias showVat: show

    Column {
        CheckBox {
            id: show
            text: qsTr("MwSt anzeigen")
            checked: false
        }

        RadioButton {
            id: pricesExclVat
            text: qsTr("Preise ohne MwSt")
            visible: show.checked
            checked: true
        }
        RadioButton {
            id: pricesInclVat
            text: qsTr("Preise mit MwSt")
            checked: !pricesExclVat.checked
            visible: show.checked
        }

        Row {
            height: childrenRect.height
            width: childrenRect.width
            spacing: 2
            Label {
                id: labelVatNumber
                text: qsTr("MwSt-Nummer")
                anchors.verticalCenter: number.verticalCenter
                visible: show.checked
            }
            TextField {
                id: number
                visible: show.checked
                placeholderText: qsTr("MwSt-Nummer")
            }
        }
        Row {
            height: childrenRect.height
            width: childrenRect.width
            spacing: 2

            Label {
                width: labelVatNumber.width
                anchors.verticalCenter: taxRate.verticalCenter
                text: qsTr("Steuersatz")
                visible: show.checked
            }
            TextField {
                id: taxRate
                width: 60
                text: "8.0"
                visible: show.checked
                placeholderText: qsTr("")
                validator: RegExpValidator {
                    regExp: /[0-9]+\.[0-9]+/
                }
            }
            Label {
                text: qsTr("%")
                anchors.verticalCenter: taxRate.verticalCenter
                visible: show.checked
            }
        }
    }
}
