import QtQuick 2.4
import QtQuick.Controls 2.0

Item {
    id: root
    property alias name: name
    width: textFieldWidth + labelWidth + spacing
    height: childrenRect.height
    property alias iban: iban
    property alias bic: bic
    property alias account: account

    property int textFieldWidth: 200
    property int labelWidth: 75
    property int spacing: 1

    Grid {
        id: grid
        anchors {
            left: parent.left
            right: parent.right
        }

        columns: 2
        spacing: root.spacing
        horizontalItemAlignment: Grid.AlignLeft
        verticalItemAlignment: Grid.AlignVCenter

        Label {
            text: qsTr("Bankname")
            width: labelWidth
        }
        TextField {
            id: name
            width: textFieldWidth
            placeholderText: qsTr("")
        }

        Label {
            text: qsTr("Konto Nr.")
            width: labelWidth
        }
        TextField {
            id: account
            width: textFieldWidth
            placeholderText: qsTr("")
        }

        Label {
            text: qsTr("Swift/BIC")
            width: labelWidth
        }
        TextField {
            id: bic
            width: textFieldWidth
            placeholderText: qsTr("")
        }

        Label {
            text: qsTr("IBAN")
            width: labelWidth
        }
        TextField {
            id: iban
            width: textFieldWidth
            placeholderText: qsTr("")
        }
    }
}
