import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import "components"
import HmiEnum 1.0

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

    property string tempEmployeeName: selectedEmployeeName
    property int tempAssemplySkill: selectedAssemblySkill
    property int tempCppSkill: selectedCskill
    property int tempJsSkill: selectedJSSkill
    property int tempQmlSkill: selectedQMLSkill
    property int tempOpenglSkill: selectedOpenGLSkill

    onSelectedEmployeeIdChanged: {
        console.log("[main.qml][onSelectedEmployeeIdChanged][" + selectedEmployeeId + "]")
    }

    TextField {
        id: titleText
        anchors.top: parent.top
        anchors.topMargin: 50
        anchors.left: parent.left
        anchors.leftMargin: 80
        anchors.right: parent.right
        anchors.rightMargin: 80
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 30
        text: selectedEmployeeName
        onTextChanged: tempEmployeeName = text
        font.bold: true
        font.capitalization: Font.AllUppercase
        background: Rectangle {
            border.color: "#90A17D"
            border.width: 2
            radius: 5
        }
    }

    EmployeeSkillComponent {
        id: assemblySkill
        anchors.left: parent.left
        anchors.top: titleText.top
        anchors.topMargin: 100
        skillName: nameSkill[skillId-1]
        skillGradeText: selectedAssemblySkill
        skillId: 1
        isGoodSkill: selectedAssemblySkill >= goodGrade
        onScoreTextChanged: tempAssemplySkill = parseInt(scoreText)
    }

    EmployeeSkillComponent {
        id: cplplSkill
        anchors.left: parent.left
        anchors.top: assemblySkill.top
        anchors.topMargin: 70
        skillName: nameSkill[skillId-1]
        skillGradeText: selectedCskill
        skillId: 2
        isGoodSkill: selectedCskill >= goodGrade
        onScoreTextChanged: tempCppSkill= parseInt(scoreText)
    }

    EmployeeSkillComponent {
        id: javaSkill
        anchors.left: parent.left
        anchors.top: cplplSkill.top
        anchors.topMargin: 70
        skillName: nameSkill[skillId-1]
        skillGradeText: selectedJSSkill
        skillId: 3
        isGoodSkill: selectedJSSkill >= goodGrade
        onScoreTextChanged: tempJsSkill= parseInt(scoreText)
    }

    EmployeeSkillComponent {
        id: qmlSkill
        anchors.left: parent.left
        anchors.top: javaSkill.top
        anchors.topMargin: 70
        skillName: nameSkill[skillId-1]
        skillGradeText: selectedQMLSkill
        skillId: 4
        isGoodSkill: selectedQMLSkill >= goodGrade
        onScoreTextChanged: tempQmlSkill = parseInt(scoreText)
    }

    EmployeeSkillComponent {
        id: openGLSkill
        anchors.left: parent.left
        anchors.top: qmlSkill.top
        anchors.topMargin: 70
        skillName: nameSkill[skillId-1]
        skillGradeText: selectedOpenGLSkill
        skillId: 5
        isGoodSkill: selectedOpenGLSkill >= goodGrade
        onScoreTextChanged: tempOpenglSkill = parseInt(scoreText)
    }

    GeneralButton {
        id: buttonRefresh
        anchors.top: openGLSkill.top
        anchors.topMargin: 70
        anchors.horizontalCenter: parent.horizontalCenter
        buttonName: "Update"
        onClickButton: {
            console.log("[main.qml][Update Button][onClickButton]")
            myAppMain.requestToUpdateEmployeeInfo(selectedEmployeeId, tempEmployeeName, tempAssemplySkill, tempCppSkill, tempJsSkill, tempQmlSkill, tempOpenglSkill)
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
                    myAppMain.requestToSelectEmployee(employeeId, tempEmployeeName, )
                }
            }
        }
    }
}

