import QtQuick 2.0
import QtQuick.Dialogs 1.2



Item {
    Dialog {
        id: dialog
        title: qsTr("Position ändern")

        property var rowIndex

        contentItem: Position {
            id: modifyPosition
            implicitWidth: childrenRect.width
            implicitHeight: childrenRect.height

            btnOK.onClicked: {
                positionContainerModel.setRow(
                    dialog.rowIndex,
                    modifyPosition.standard.description.text,
                    modifyPosition.standard.unit.text,
                    modifyPosition.standard.numUnits.text,
                    modifyPosition.standard.pricePerUnit.text
                )
                dialog.click(StandardButton.Ok)
            }
            btnCancel.onClicked: {
                dialog.click(StandardButton.Cancel)
            }

        }

        Text {
            // Dirty way to store the row index from the set() function s.t. it can be used
            // from the onClicked function.
            //id: rowIndex
        }

        function set(row) {
            dialog.rowIndex = row
            var pos = positionContainerModel.getRow( row )
            modifyPosition.standard.description.text  = pos.description
            modifyPosition.standard.unit.text         = pos.unit
            modifyPosition.standard.numUnits.text     = pos.numUnits
            modifyPosition.standard.pricePerUnit.text = pos.pricePerUnit
        }
    }

    function open(row) {
        dialog.set( row )
        dialog.open()
    }
}
