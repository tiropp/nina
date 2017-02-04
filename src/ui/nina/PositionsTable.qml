import QtQuick 2.4

PositionsTableForm {
    ModifyPositionDialog {
        id: modifyPositionDialog
    }

    positions.onDoubleClicked: {
        modifyPositionDialog.open( positions.__currentRow )
    }

    function getCurrentRow() {
        return positions.__currentRow
    }
}
