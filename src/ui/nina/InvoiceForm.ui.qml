import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

Item {
    id: invoiceForm
    width: 800
    height: 600
    property alias positions: positions
    property alias settings: settings


    SplitView {
        anchors.fill: parent
        orientation: Qt.Horizontal

        InvoicePositions {
            id: positions
            Layout.fillWidth: true
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

