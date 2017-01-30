import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

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

    /*
    Flickable {
        anchors.fill: parent
        contentHeight: invoice.height

        ScrollBar.vertical: ScrollBar {}

        Invoice {
            id: invoice
        }
    }
    */

    InvoiceTest {

    }

}
