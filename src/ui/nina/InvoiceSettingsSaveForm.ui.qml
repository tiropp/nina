import QtQuick 2.4
import QtQuick.Controls 2.0

Item {
    id: item1
    width: 400
    height: 400
    property alias btnSaveDefault: btnSaveDefault

    Button {
        id: btnSaveDefault
        text: qsTr("Als Standard übnehmen")
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10
    }
}
