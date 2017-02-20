import QtQuick 2.4

InvoiceSettingsSaveForm {
    btnSaveDefault.onClicked: {
        invoiceModel.saveDefaultSettings()
    }
}
