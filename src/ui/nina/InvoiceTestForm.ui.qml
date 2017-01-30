import QtQuick 2.4
import QtQuick.Controls 2.0

Item {
    id: item1
    width: 800
    height: 600

    Row {
        id: row
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        Column {
            id: column
            width: 500

            Rectangle {
                id: rectangle
                width: 200
                height: 200
                color: "#cd1c1c"
            }

            Rectangle {
                id: rectangle1
                width: 200
                height: 200
                color: "#719105"
            }


        }

        Column {
            id: column1
            x: 400

            Rectangle {
                id: rectangle2
                width: 200
                height: 200
                color: "#2e0b74"
            }


        }


    }
}
