import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls 1.4


ApplicationWindow {
    id: appWindow
    visible: true
    width: 800
    height: 600
    title: qsTr("Nina")


    /*
    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        WelcomePage {
        }

        Page {
            Label {
                text: qsTr("Second page")
                anchors.centerIn: parent
            }
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("First")
        }
        TabButton {
            text: qsTr("Second")
        }
    }
    */

    menuBar: MenuBar {
        Menu {
            title: qsTr("Datei")

            MenuItem {
                text: qsTr("Öffnen")
                shortcut: "Ctrl+O"
                onTriggered: invoice.open()
            }
            MenuItem {
                text: qsTr("Speichern")
                shortcut: "Ctrl+S"
                onTriggered: invoice.save()
            }
        }
        Menu {
            title: qsTr("Tools")

            MenuItem {
                text: qsTr("PDF erzeugen")
                shortcut: "Ctrl+C"
                onTriggered: invoice.createPdf()
            }
        }
    }

    Invoice {
        id: invoice
        width: parent.widh - settings.width
    }




}
