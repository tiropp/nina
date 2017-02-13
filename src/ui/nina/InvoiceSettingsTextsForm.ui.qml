import QtQuick 2.4
import QtQuick.Controls 2.0

Item {
    width: 400
    height: childrenRect.height
    property alias afterPositions: afterPositions
    property alias beforePositions: beforePositions

    Column {
        width: parent.width
        Label {
            id: labelTextBeforePositions
            text: qsTr("Text vor Positionen")
        }
        TextArea {
            id: beforePositions
            width: parent.width
            height: 200
            wrapMode: Text.WordWrap
        }

        Label {
            id: label1TextAfterPosition
            text: qsTr("Text nach Positionen")
        }


        TextArea {
            id: afterPositions
            width: parent.width
            height: 200
            wrapMode: Text.WordWrap
        }
    }
}
