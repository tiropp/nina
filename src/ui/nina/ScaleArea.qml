import QtQuick 2.0

Item {
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
