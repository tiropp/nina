import QtQuick 2.4
import QtQuick.Controls 2.0


Item {
    id: root
    width: textFieldWidth + labelWidth + spacing
    height: childrenRect.height
    property alias signature: signature
    property alias greetings: greetings
    property alias title: title

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
            text: qsTr("Titel")
        }
        TextField {
            id: title
            text: "Rechnung"
            placeholderText: qsTr("")
        }

        Label {
            text: qsTr("Schlussklausel")
        }
        TextField {
            id: greetings
            text: "Mit freundlichen Grüssen"
            placeholderText: qsTr("")
        }

        Label {
            text: qsTr("Signatur")
        }
        TextField {
            id: signature
            placeholderText: qsTr("")
        }

        Rectangle{ width: 1; height: 1; } /*placeholder*/
        Label {
            text: qsTr("(default: Absendername)")
        }
    }

}
