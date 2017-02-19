import QtQuick 2.4
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1


Item {
    width:  300
    height: childrenRect.height
    property alias misc: misc
    property alias font: fonts
    property alias vat: vat
    property alias bank: bank
    property alias date: date
    property alias texts: texts
    property alias receiver: receiver
    property alias sender: sender

    Column {
        anchors.fill: parent
        spacing: 1

        AccordionItem {
            title: qsTr("Absender")
            contents: InvoiceSettingsSender {
                id: sender
            }
        }
        AccordionItem {
            title: qsTr("Anschrift")
            contents: InvoiceSettingsReceiver {
                id: receiver
            }
        }
        AccordionItem {
            title: qsTr("Texte")
            width: parent.width
            contents: InvoiceSettingsTexts {
                id: texts
            }
        }
        AccordionItem {
            title: qsTr("Datum")
            contents: InvoiceSettingsDate {
                id: date
            }
        }
        AccordionItem {
            title: qsTr("Bankverbindung")
            contents: InvoiceSettingsBank {
                id: bank
            }
        }
        AccordionItem {
            title: qsTr("Mehrwertsteuer")
            contents: InvoiceSettingsVat {
                id: vat
            }
        }
        AccordionItem {
            title: qsTr("Schriftgrösse")
            contents: InvoiceSettingsFont {
                id: fonts
            }
        }
        AccordionItem {
            title: qsTr("Sonstiges")
            contents: InvoiceSettingsMisc {
                id: misc
            }
        }
    }
}
