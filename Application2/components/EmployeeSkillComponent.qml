import QtQuick 2.0
import QtQuick.Controls 2.14
import "../image"

Item {
    id: root

    height: 40
    width: parent.width
    property int skillId: -1
    property string imageSource: ""
    property string skillName: ""
    property string skillGradeText: ""
    property bool isGoodSkill: false
    property string scoreText


    function getImageSoureFromSkillId(_skillId) {
        switch (_skillId) {
        case 1:
            return "../image/assembly.png"
        case 2:
            return "../image/cpp.png"
        case 3:
            return "../image/java.png"
        case 4:
            return "../image/qml.png"
        case 5:
            return "../image/opengl.png"
        default:
            return ""
        }
    }

    Image {
        id: skillIcon
        anchors.left: parent.left
        anchors.leftMargin: 100
        source: getImageSoureFromSkillId(skillId)
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

    TextField {
        id: gradeOfSkill
        text: skillGradeText
        width: 50
        anchors.left: skillIcon.left
        anchors.leftMargin: 200
        font.pixelSize: 20
        anchors.verticalCenter: parent.verticalCenter
        background: Rectangle {
            border.color: "#90A17D"
            border.width: 2
            radius: 5
        }

        onTextChanged: {
            scoreText = text
        }
    }

    Image {
        id: verifySkill
        anchors.left: parent.left
        anchors.leftMargin: 400
        source: isGoodSkill ? "../image/ok_icon.png" : "../image/cancel_icon100.png"
        width: 40
        height: 40
        sourceSize.width: 50
        sourceSize.height: 50
    }
}
