import QtQuick 2.5
import QtQuick.Controls 2.0


Item {
    id: invoiceForm
    width: 800
    height: 600
    property alias positions: positions
    property alias settings: settings
    anchors.fill: parent


    Row {
        anchors.fill: parent.fill
        height: parent.height
        width: parent.width

        InvoicePositions {
            id: positions
            width: parent.width - flickSettings.width
            height: parent.height

        }

        Flickable {
            id: flickSettings
            width: 300
            height: parent.height

            ScrollBar.vertical: ScrollBar {}

            InvoiceSettings {
                id: settings
            }
        }
    }

}

