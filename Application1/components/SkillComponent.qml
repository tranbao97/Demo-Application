import QtQuick 2.0

Item {
    id: root

    width: 550
    height: 950

    property string imageSource: ""
    property string skillName: ""
    property string skillGradeText: ""
    property bool isGoodSkill: false

    Image {
        id: skillIcon
        anchors.left: parent.left
        anchors.leftMargin: 100
        source: imageSource
        width: 40
        height: 40
        sourceSize.width: 50
        sourceSize.height: 50
    }

    Text {
        id: nameOfSkill
        text: skillName
        anchors.left: skillIcon.left
        anchors.leftMargin: 70
        font.pixelSize: 20
        anchors.verticalCenter: parent.verticalCenter
    }

    Text {
        id: gradeOfSkill
        text: skillGradeText
        anchors.left: skillIcon.left
        anchors.leftMargin: 200
        font.pixelSize: 20
        anchors.verticalCenter: parent.verticalCenter
    }

    Image {
        id: verifySkill
        anchors.left: parent.left
        anchors.leftMargin: 400
        source: isGoodSkill ? "../image/good_icon.png" : "../image/not_good_icon.png"
        width: 40
        height: 40
        sourceSize.width: 50
        sourceSize.height: 50
    }
}
