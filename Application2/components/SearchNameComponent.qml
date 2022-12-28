import QtQuick 2.0
import QtQuick.Controls 2.14

Item {
    id: container
    width: 400
    height: 20

    property string searchName: ""

    Text {
        id: nameToSearch
        font.pixelSize: 20
        text: "Search Name: "
    }

    TextField {
        id: searchItem
        anchors.verticalCenter: nameToSearch.verticalCenter
        anchors.left: nameToSearch.right
        text: ""
        width: 350
        font.pixelSize: 20
        onTextChanged: searchName = text
        background: Rectangle {
            border.color: "#90A17D"
            border.width: 2
            radius: 5
        }
    }
}
