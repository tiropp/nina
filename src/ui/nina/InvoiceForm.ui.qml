import QtQuick 2.5
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4

Item {
    id: invoiceForm
    width: 800
    height: 600
    property alias positions: positions
    property alias settings: settings
    property alias btnLoad: btnLoad
    property alias btnSave: btnSave
    property alias btnCreatePdf: btnCreatePdf
    anchors.fill: parent

    Column {
        height: parent.height
        anchors {
            left: parent.left
            right: parent.right
        }

        Row {
            anchors {
                left: parent.left
                right: parent.right
            }
            height: parent.height - rowButtons.height

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
        Row {
            id: rowButtons
            anchors.left: parent.left

            Button {
                id: btnCreatePdf
                text: qsTr("PDF erzeugen")
            }

            Button {
                id: btnSave
                text: qsTr("Speichern")
            }

            Button {
                id: btnLoad
                text: qsTr("Laden")
            }
        }
    }
}

