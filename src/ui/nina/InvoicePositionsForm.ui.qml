import QtQuick 2.4
import QtQuick.Controls 2.0


Item {    
    width: 400
    height: 400
    property alias btnDeletePos: btnDeletePos
    property alias btnModifyPos: btnModifyPos
    property alias btnNewPos: btnNewPos

    PositionsTable {
        id: positions
        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
        }
        height: parent.height - rowButtons.height
    }

    Row {
        id: rowButtons
        anchors {
            top: positions.bottom
            left: parent.left
            bottom: parent.bootom
        }
        Button {
            id: btnNewPos
            text: qsTr("Neue Position")
        }

        Button {
            id: btnModifyPos
            text: qsTr("Ändern")
        }

        Button {
            id: btnDeletePos
            text: qsTr("Entfernen")
        }
    }
}
