import QtQuick 2.4

InvoicePositionsForm {
    AddPositionDialog {
        id: addPositionDialog
    }
    ModifyPositionDialog {
        id: modifyPositionDialog
    }

    btnNewPos.onClicked: {
        addPositionDialog.open()
    }

    btnModifyPos.onClicked: {
        modifyPositionDialog.open( positions.getCurrentRow() )
    }

    btnDeletePos.onClicked: {
        positionContainerModel.removeRow( positions.getCurrentRow() )
    }
}
