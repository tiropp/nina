import QtQuick 2.4
import QtQuick.Controls 2.0
import "ColumnHelper.js" as ColumnHelper


Item {
    width: 400
    height: 400

    ModifyPositionDialog {
        id: modifyPositionDialog
    }

    ListView {
        id: positions
        anchors.fill: parent
        property variant columnWidths: ColumnHelper.calcColumnHeaderWidth(tabHeader, positions)
        model: positionContainerModel
        delegate: PositionsTableItem {}
        header: tabHeader

        Component {
            id: tabHeader
            PositionsTableHeaderItem {}
        }

        Connections {
            target: positionContainerModel
            onAppended: {
                var widths = ColumnHelper.calcColumnWidths(positionContainerModel, positions)
                positions.columnWidths = widths

                // Will update all rowsm, s.t. the column conditions is correct for
                // all of them
                positionContainerModel.refresh()
            }
        }

        highlight: Component {
            Rectangle {
            color:"lightsteelblue"
            radius: 5
            opacity: 0.7
            }
        }
        focus: true

        ScrollBar.vertical: ScrollBar {}

        function modify(index) {
            modifyPositionDialog.open( index )
        }
        function remove(index) {
            positionContainerModel.removeRow( index )
        }
    }

    function modifyCurrent() {
        modifyPositionDialog.open( positions.currentIndex )
    }

    function removeCurrent() {
        positionContainerModel.removeRow( positions.currentIndex )
    }
}
