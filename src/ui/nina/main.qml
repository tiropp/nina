import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import "."


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
        style: MenuBarStyle {
            background: Rectangle {
                color: Style.bgColor
                border.color: Style.bgBorderColor
            }
            menuStyle: MenuStyle {
                frame: Rectangle {
                    color: Style.bgColor
                    border.color: Style.bgBorderColor
                }
            }
        }

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


    Rectangle {
        color: "#ffffff"
        anchors.fill: parent


        Flickable {
            id: scaleArea
            anchors.fill: parent
            transformOrigin: Item.TopLeft
            contentHeight: height / scale
            contentWidth:  width  / scale

            Invoice {
                id: invoice
                anchors.fill: parent
            }
        }

        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.ControlModifier
            onWheel: {
                if( wheel.modifiers & Qt.ControlModifier ) {
                    var change = wheel.angleDelta.y/120
                    scaleArea.scale += change/10;
                }
            }
        }
    }
}
