import QtQuick 2.4
import QtQuick.Controls 2.0

Item {
    id: root
    property alias name: name
    width: textFieldWidth + labelWidth + spacing
    height: childrenRect.height
    property alias phoneInBottomLine: phoneInBottomLine
    property alias webpage: webpage
    property alias email: email
    property alias mobilePhone: mobilePhone
    property alias phone: phone
    property alias country: country
    property alias place: place
    property alias zipCode: zipCode
    property alias street: street
    property alias company: company

    property int textFieldWidth: 200
    property int labelWidth: 75
    property int spacing: 1

    Grid {
        id: grid
        y: 0
        anchors.rightMargin: 0
        anchors.leftMargin: 0
        anchors {
            left: parent.left
            right: parent.right
        }

        columns: 2
        spacing: root.spacing
        horizontalItemAlignment: Grid.AlignLeft
        verticalItemAlignment: Grid.AlignVCenter

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
            width: textFieldWidth
            text: qsTr("")
        }

        Label {
            text: qsTr("Telefon")
            width: labelWidth
        }
        TextField {
            id: phone
            width: textFieldWidth
            text: qsTr("")
        }

        Label {
            text: qsTr("Natel")
            width: labelWidth
        }
        TextField {
            id: mobilePhone
            width: textFieldWidth
            text: qsTr("")
        }

        Label {
            text: qsTr("E-Mail")
            width: labelWidth
        }
        TextField {
            id: email
            width: textFieldWidth
            text: qsTr("")
        }

        Label {
            text: qsTr("Webpage")
            width: labelWidth
        }
        TextField {
            id: webpage
            width: textFieldWidth
            text: qsTr("")
        }
    }

    CheckBox {
        id: phoneInBottomLine
        text: qsTr("Telefon, Natel in Bottom-Line")
        anchors.top: grid.bottom
    }
}
