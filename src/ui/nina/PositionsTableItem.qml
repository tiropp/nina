import QtQuick 2.0
import QtQuick.Layouts 1.1


Component {
    Item {
        width: parent.width - 15
        height: childrenRect.height

        function altColor(i) {
            if( i < 0 )
                return "#ffffff"
            var colors = ["#b7b7b7", "#888888"];
            return colors[i];
        }


        Rectangle {
            id: background
            width: parent.width + 15
            height: row.height
            color: altColor( index % 2 )
            opacity: 0.3
        }

        RowLayout {
            id: row
            width: parent.width
            spacing: 5

            Item {
                width: 5
                height: 1
            }

            Text {
                id: descr
                Layout.fillWidth: true
                text: model.description
            }
            Loader { sourceComponent: columnSeparator; height: descr.height }

            Text {
                width: positions.columnWidths['unit']
                Layout.minimumWidth: width
                text: model.unit
            }
            Loader { sourceComponent: columnSeparator; height: descr.height }

            Text {
                width: positions.columnWidths['numUnits']
                Layout.minimumWidth: width
                text: model.numUnits
            }
            Loader { sourceComponent: columnSeparator; height: descr.height }

            Text {
                width: positions.columnWidths['pricePerUnit']
                Layout.minimumWidth: width
                text: model.pricePerUnit
            }

            Component {
                id: columnSeparator
                Rectangle {
                    width: 1
                    color: "black"
                    opacity: 0.3
                }
             }
        }

        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton
            onClicked: {
                positions.currentIndex = index
            }
            onDoubleClicked: {
                positions.modify( index )
            }
        }
    }
}
