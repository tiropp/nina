import QtQuick 2.4
import QtQuick.Controls 2.0

Item {
    id: root
    width: childrenRect.width
    height: childrenRect.height
    property alias year: year
    property alias month: month
    property alias day: day
    property alias useSpecified: useSpecified
    property alias useToday: useToday

    RadioButton {
        id: useToday
        text: qsTr(" heutiges Datum")
        anchors {
            left: parent.left
            top: parent.top
        }
        checked: true
    }

    RadioButton {
        id: useSpecified
        text: qsTr("Datum eingeben:")
        anchors {
            left: parent.left
            top: useToday.bottom
        }
    }
    TextField {
        id: day
        anchors {
            left: useSpecified.right
            verticalCenter: useSpecified.verticalCenter
        }
        width: 35
        height: 40
        visible: useSpecified.checked
        placeholderText: qsTr("TT")
    }
    TextField {
        id: month
        anchors {
            left: day.right
            verticalCenter: useSpecified.verticalCenter
        }
        width: 37
        height: 40
        visible: useSpecified.checked
        placeholderText: qsTr("MM")
    }
    TextField {
        id: year
        anchors {
            left: month.right
            verticalCenter: useSpecified.verticalCenter
        }
        width: 50
        height: 40
        visible: useSpecified.checked
        placeholderText: qsTr("JJJJ")
    }
}
