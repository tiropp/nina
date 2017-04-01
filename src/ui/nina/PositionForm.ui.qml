import QtQuick 2.4
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item {
    width: 500
    height: 400
    property alias btnCancel: btnCancel
    property alias btnOK: btnOK
    property alias standard: standard

    ScaleArea {
        anchors.fill: parent
        contentItem: ColumnLayout {
            id: columnLayout

            PositionStandard {
                anchors.fill: parent
                id: standard
            }

            ToolBar {
                id: toolBar
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
    }
}
