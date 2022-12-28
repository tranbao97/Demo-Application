import QtQuick 2.0

Item {
    id: container
    width: 150; height: 50
    signal clickButton()
    property string buttonName: "Refresh"

    Rectangle {
        anchors.fill: parent
        width: parent.width; height: parent.height
        color: "green"
        radius: 10
    }

    Text {
        anchors.fill: parent
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 20
        text: buttonName
        font.capitalization: Font.AllUppercase
        font.bold: true
        color: "white"
    }


    MouseArea {
        anchors.fill: parent
        onClicked: container.clickButton()
    }
}
