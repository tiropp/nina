import QtQuick 2.4
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import "."


Item {
    width: 300
    height: childrenRect.height
    property alias afterPositions: afterPositions
    property alias beforePositions: beforePositions

    Column {
        anchors {
            left: parent.left
            right: parent.right
        }
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

            background: Rectangle {
                border.color: Style.bgBorderColor
            }
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

            background: Rectangle {
                border.color: Style.bgBorderColor
            }
        }
    }
}
