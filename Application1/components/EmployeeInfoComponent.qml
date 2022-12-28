import QtQuick 2.0

Item {
    id: root
    width: 510
    height: 30
    property string name: ""
    property string grade: ""
    property string score: ""
    property bool isLable: false
    property bool selected: false

    Rectangle {
        id: selectedItem
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.rightMargin: 10
        height: parent.height
        width: parent.width
        color: "#9BA17B"
        visible: selected
    }

    Text {
        id: nameLable
        anchors.left: parent.left
        anchors.leftMargin: 50
        text: name
        font.bold: isLable
        font.capitalization: isLable ? Font.AllUppercase : Font.MixedCase
        font.pixelSize: isLable ? 20 : 15
        anchors.verticalCenter: parent.verticalCenter
    }

    Text {
        id: scoreLable
        anchors.left: parent.left
        anchors.leftMargin: isLable ? 400 : 420
        text: score
        font.bold: isLable
        font.capitalization: isLable ? Font.AllUppercase : Font.MixedCase
        font.pixelSize: isLable ? 20 : 15
        anchors.verticalCenter: parent.verticalCenter
    }
}
