import QtQuick 2.4
import QtQuick.Controls 2.0

Item {
    id: root
    width: textFieldWidth + labelWidth + spacing
    height: childrenRect.height
    property alias positionSkip: positionSkip
    property alias fontSkip: fontSkip
    property alias fontSize: fontSize

    property int textFieldWidth: 60
    property int labelWidth: 120
    property int spacing: 1

    Grid {
        id: grid
        anchors {
            left: parent.left
            right: parent.right
        }

        columns: 3
        spacing: root.spacing
        horizontalItemAlignment: Grid.AlignLeft
        verticalItemAlignment: Grid.AlignVCenter

        Label {
            text: qsTr("Schriftgrösse")
            width: labelWidth
        }
        TextField {
            id: fontSize
            width: textFieldWidth
            text: "12"
            placeholderText: qsTr("")
        }
        Label {
            text: qsTr("pt")
        }

        Label {
            text: qsTr("Schriftabstand")
            width: labelWidth
        }
        TextField {
            id: fontSkip
            width: textFieldWidth
            text: "18"
            placeholderText: qsTr("")
        }
        Label {
            text: qsTr("pt")
        }

        Label {
            text: qsTr("zusätzlicher Abstand zwischen den einzelnen Positionen")
            width: labelWidth
            wrapMode: Text.WordWrap
        }
        TextField {
            id: positionSkip
            width: textFieldWidth
            text: "0"
            placeholderText: qsTr("")
        }
        Label {
            text: qsTr("pt")
        }
    }
}
