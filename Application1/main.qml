import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import "components"
import HmiEnum 1.0
import QtQuick.Controls.Styles 1.4

Item {
    id: container
    width: 550
    height: 950

    property string selectedEmployeeName: myEmployeeModel.getDataByEmployeeId(selectedEmployeeId, HmiEnum.E_HMI_ROLE_EMPLOYEE_NAME)
    property int selectedAssemblySkill: myEmployeeModel.getDataByEmployeeId(selectedEmployeeId, HmiEnum.E_HMI_ROLE_ASSEMBLY_SCORE)
    property int selectedCskill: myEmployeeModel.getDataByEmployeeId(selectedEmployeeId, HmiEnum.E_HMI_ROLE_CPP_SCORE)
    property int selectedJSSkill: myEmployeeModel.getDataByEmployeeId(selectedEmployeeId, HmiEnum.E_HMI_ROLE_JAVA_SCORE)
    property int selectedQMLSkill: myEmployeeModel.getDataByEmployeeId(selectedEmployeeId, HmiEnum.E_HMI_ROLE_QML_SCORE)
    property int selectedOpenGLSkill: myEmployeeModel.getDataByEmployeeId(selectedEmployeeId, HmiEnum.E_HMI_ROLE_OPENGL_SCORE)
    property int maxGrade: 5
    property int goodGrade: 3
    property var nameSkill: ["Assembly", "C++", "Java Script", "QML", "OpenGL"]
    property int selectedEmployeeId: myAppMain.selectedEmployeeId

    onSelectedEmployeeIdChanged: {
        console.log("[main.qml][onSelectedEmployeeIdChanged][" + selectedEmployeeId + "]")
    }

//    TextField {
//        id: titleText
//        anchors.top: parent.top
//        anchors.topMargin: 50
//        anchors.left: parent.left
//        anchors.right: parent.right
//        horizontalAlignment: Text.AlignHCenter
//        font.pixelSize: 30
//        text: selectedEmployeeName
//        font.bold: true
//        font.capitalization: Font.AllUppercase
//    }

    Text {
        id: titleText
        anchors.top: parent.top
        anchors.topMargin: 50
        anchors.left: parent.left
        anchors.right: parent.right
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 30
        text: selectedEmployeeName
        font.bold: true
        font.capitalization: Font.AllUppercase
    }

    EmployeeSkillComponent {
        id: assemblySkill
        anchors.left: parent.left
        anchors.top: titleText.top
        anchors.topMargin: 100
        skillName: nameSkill[skillId-1]
        skillGradeText: "%1/5".arg(selectedAssemblySkill)
        skillId: 1
        isGoodSkill: selectedAssemblySkill >= goodGrade
    }

    EmployeeSkillComponent {
        id: cplplSkill
        anchors.left: parent.left
        anchors.top: assemblySkill.top
        anchors.topMargin: 70
        skillName: nameSkill[skillId-1]
        skillGradeText: "%1/5".arg(selectedCskill)
        skillId: 2
        isGoodSkill: selectedCskill >= goodGrade
    }

    EmployeeSkillComponent {
        id: javaSkill
        anchors.left: parent.left
        anchors.top: cplplSkill.top
        anchors.topMargin: 70
        skillName: nameSkill[skillId-1]
        skillGradeText: "%1/5".arg(selectedJSSkill)
        skillId: 3
        isGoodSkill: selectedJSSkill >= goodGrade
    }

    EmployeeSkillComponent {
        id: qmlSkill
        anchors.left: parent.left
        anchors.top: javaSkill.top
        anchors.topMargin: 70
        skillName: nameSkill[skillId-1]
        skillGradeText: "%1/5".arg(selectedQMLSkill)
        skillId: 4
        isGoodSkill: selectedQMLSkill >= goodGrade
    }

    EmployeeSkillComponent {
        id: openGLSkill
        anchors.left: parent.left
        anchors.top: qmlSkill.top
        anchors.topMargin: 70
        skillName: nameSkill[skillId-1]
        skillGradeText: "%1/5".arg(selectedOpenGLSkill)
        skillId: 5
        isGoodSkill: selectedOpenGLSkill >= goodGrade
    }

    GeneralButton {
        id: buttonRefresh
        anchors.top: openGLSkill.top
        anchors.topMargin: 70
        anchors.horizontalCenter: parent.horizontalCenter
        onClickButton: {
            console.log("[main.qml][Refresh Button][onClickButton]")
            //requestGetEmployeeList()
            loopComp.visible = true
            loopComp.start()
            timerLoadingAnimation.restart()
        }
    }

    SearchNameComponent {
        id: searchNameComp
        anchors.top: buttonRefresh.top
        anchors.topMargin: 70
        anchors.left: parent.left
        anchors.leftMargin: 10
        onSearchNameChanged: {
            myAppMain.requestToSearchEmployeeName(searchName)
        }
    }

    Item {
        id: lableOfListEmployees
        anchors.top: searchNameComp.top
        anchors.topMargin: 30
        anchors.horizontalCenter: parent.horizontalCenter
        width: 510
        height:employeeLable.height
        EmployeeInfoComponent {
            id: employeeLable
            name: "Name"
            grade: "Grade"
            score: "Average"
            isLable: true
        }
    }

    Item {
        id: listOfEmployees
        width: 510
        anchors.top: lableOfListEmployees.top
        anchors.topMargin: 50
        anchors.horizontalCenter: parent.horizontalCenter
        ListView{
            id: lv
            width: 500
            height: 250
            anchors.horizontalCenter: parent.horizontalCenter
            model: myEmployeeModel2
            spacing: 0
            delegate: employeeComp
            snapMode: ListView.SnapToItem
            orientation: Qt.Vertical
            contentWidth: 0
            visible: !loopComp.visible
            clip: true
        }
    }

    Component {
        id: employeeComp
        EmployeeInfoComponent {
            id: employeeInfo
            name: employeeName
            grade: employeeGrade
            score: averageScore
            isLable: false
            selected: employeeId === selectedEmployeeId
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    //selectedEmployeeId = employeeId
                    myAppMain.requestToSelectEmployee(employeeId)
                }
            }
        }
    }

    AnimationLoading {
        id: loopComp
        anchors.top: lableOfListEmployees.top
        anchors.topMargin: 100
        anchors.horizontalCenter: parent.horizontalCenter
        visible: false
    }

    Timer {
        id: timerLoadingAnimation
        repeat: false
        interval: 3000
        onTriggered: {
            console.log("[main.qml][timerLoadingAnimation][onTriggered]")
            loopComp.visible = false
            loopComp.stop()
        }
    }
}
