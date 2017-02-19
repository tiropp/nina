import QtQuick 2.4

InvoicePositionsForm {
    AddPositionDialog {
        id: addPositionDialog
    }

    btnNewPos.onClicked: {
        addPositionDialog.open()
    }

    btnModifyPos.onClicked: {
        positions.modifyCurrent()
    }

    btnDeletePos.onClicked: {
        positions.removeCurrent()
    }
}
