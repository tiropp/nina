import QtQuick 2.4
import QtQuick.Controls 2.0

Item {
    id: root
    property alias name: name
    width: textFieldWidth + labelWidth + spacing
    height: childrenRect.height
    property alias usePoBox: usePoBox
    property alias country: country
    property alias place: place
    property alias street: street
    property alias zipCode: zipCode
    property alias company: company
    property alias salutation: salutation

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
            text: qsTr("Andrede")
            width: labelWidth
        }
        TextField {
            id: salutation
            width: textFieldWidth
            text: qsTr("")
        }

        Label {
            text: qsTr("Name")
            width: labelWidth
        }
        TextField {
            id: name
            width: textFieldWidth
            text: qsTr("")
        }

        Label {
            text: qsTr("Firma")
            width: labelWidth
        }
        TextField {
            id: company
            width: textFieldWidth
            text: qsTr("")
        }

        Label {
            text: qsTr("Strasse")
            width: labelWidth
        }
        TextField {
            id: street
            width: textFieldWidth
            text: qsTr("")
        }

        Label {
            text: qsTr("PLZ/Ort")
            width: labelWidth
        }
        Rectangle {
            height: childrenRect.height
            width: childrenRect.width
            TextField {
                id: zipCode
                width: 50
                text: qsTr("")
            }
            TextField {
                id: place
                anchors.left: zipCode.right
                width: textFieldWidth - zipCode.width
                text: qsTr("")
            }
        }

        Label {
            text: qsTr("Land")
            width: labelWidth
        }
        TextField {
            id: country
            text: qsTr("")
        }

        Label {
            text: qsTr("Postfach")
        }
        CheckBox {
            id: usePoBox
        }
    }
}
