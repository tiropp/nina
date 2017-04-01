import QtQuick 2.5
import QtQuick.Dialogs 1.2



Item {

    Dialog {
        id: dialog
        property int insertIndex
        title: qsTr("Position einfühgen")        

        contentItem: Position {
            id: insertPosition
            implicitWidth: childrenRect.width
            implicitHeight: childrenRect.height

            btnOK.onClicked: {
                positionContainerModel.insert(
                    dialog.insertIndex,
                    insertPosition.standard.description.text,
                    insertPosition.standard.unit.text,
                    insertPosition.standard.numUnits.text,
                    insertPosition.standard.pricePerUnit.text
                )
                dialog.click(StandardButton.Ok)
            }
            btnCancel.onClicked: {
                dialog.click(StandardButton.Cancel)
            }
        }
    }

    function open(index) {
        insertPosition.reset()
        dialog.insertIndex = index
        dialog.open()
    }
}
