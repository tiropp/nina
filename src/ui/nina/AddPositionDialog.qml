import QtQuick 2.5
import QtQuick.Dialogs 1.2



Item {

    Dialog {
        id: dialog
        title: qsTr("Neue Position")

        contentItem: Position {
            id: addPosition
            implicitWidth: childrenRect.width
            implicitHeight: childrenRect.height

            btnOK.onClicked: {
                positionContainerModel.append(addPosition.standard.description.text,
                                              addPosition.standard.unit.text,
                                              addPosition.standard.numUnits.text,
                                              addPosition.standard.pricePerUnit.text)
                dialog.click(StandardButton.Ok)
            }
            btnCancel.onClicked: {
                dialog.click(StandardButton.Cancel)
            }
        }
    }

    function open() {
        addPosition.reset()
        dialog.open()
    }
}
