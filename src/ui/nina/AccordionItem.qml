import QtQuick 2.5


Item {
    id: root
    width: parent.width
    height: header.height + contentsContainer.height
    property string title
    property int headerHeight: 30
    property color activeColor: "#ffffff"
    property color inactiveColor: "#ffffff"
    property bool isActive: false
    default property alias contents: placeholder.children
    property string imgArrow: 'img/arrow.png'

    Component.onCompleted: { updateHeight() }
    function updateHeight() {
        if( !isActive )
            contentsContainer.height = 0
        else
            contentsContainer.height = placeholder.childrenRect.height
    }

    Column {
        anchors.left: parent.left
        anchors.right: parent.right
        spacing: 0

        Rectangle {
            id: header
            height: headerHeight
            width: parent.width
            color: root.isActive ? activeColor : inactiveColor
            Image {
                id: arrow
                fillMode: Image.PreserveAspectFit
                height: parent.height * 0.3
                source: imgArrow
                rotation: isActive ? 90 : 0
                anchors {
                    left: parent.left
                    verticalCenter: parent.verticalCenter
                    leftMargin: 10
                }
            }
            Text {
                anchors {
                    left: arrow.right
                    verticalCenter: parent.verticalCenter
                    leftMargin: 10
                }
                text: root.title
            }
            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                onClicked: {
                    root.isActive = !root.isActive
                    updateHeight()
                }
            }
        }
        Rectangle {
            id: contentsContainer
            anchors.top: header.bottom
            width: parent.width
            clip: true

            Item {
                id: placeholder
            }
        }
    }
}
