import QtQuick 2.0

Rectangle {
    default property Item contentItem
    property int scale: scaleArea.scale

    id: root

    onContentItemChanged: {
        contentItem.parent = scaleArea
        __update()
    }
    onWidthChanged: {
        __update()
    }
    onHeightChanged: {
        __update()
    }

    Flickable {
         id: scaleArea
         anchors.fill: parent
         transformOrigin: Item.TopLeft
    }

    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.ControlModifier
        onWheel: {
            if( wheel.modifiers & Qt.ControlModifier ) {
                var change = wheel.angleDelta.y/120

                scaleArea.scale += change/10;
                __update()
            }
        }
    }

    function __update() {
        contentItem.width  = scaleArea.width / scaleArea.scale
        contentItem.height = scaleArea.height / scaleArea.scale
    }
}
