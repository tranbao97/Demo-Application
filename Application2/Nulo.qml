import QtQuick 2.9

Item {
    id: root
    objectName: "nulo"

    height: 0
    width: 0
    z: 1000

    property string color: randomColor
    property string text
    property string bottomText

    property var colorList: ["red", "fuchsia", "firebrick", "gold", "lime"
        , "limegreen", "mediumvioletred", "orangered", "royalblue", "springgreen"
        , "#16a085", "#27ae60", "#2980b9", "#8e44ad"
        , "#f1c40f", "#e67e22", "#e74c3c", "#ecf0f1"]

    property color itemColor: "red"
    property color mouseAreaColor: "deeppink"
    property color randomColor: colorList[Math.floor(Math.random()*(colorList.length - 1))]
    property bool grid: false
    property bool ruler: false
    property bool fill: false
    property bool colorText: false
    property int recursive: 0 //0, 1, 2,...
    property var target: root.parent

    Rectangle {
        id: rec
        height: target.height
        width: target.width
        color: fill ? root.color : "transparent"
        opacity: fill ? 0.2 : 1
        border.color: root.color

        Canvas{
            id: grid
            visible: root.grid
            anchors.fill : parent
            property int wgrid: 50
            onPaint: {
                var ctx = getContext("2d")
                ctx.lineWidth = 1
                ctx.strokeStyle = root.color
                ctx.beginPath()
                var nrows = height/wgrid;
                for(var i=0; i < nrows+1; i++){
                    ctx.moveTo(0, wgrid*i);
                    ctx.lineTo(width, wgrid*i);
                }

                var ncols = width/wgrid
                for(var j=0; j < ncols+1; j++){
                    ctx.moveTo(wgrid*j, 0);
                    ctx.lineTo(wgrid*j, height);
                }
                ctx.closePath()
                ctx.stroke()
            }
        }

        Canvas{
            id: ruler
            visible: root.ruler
            anchors.fill : parent

            onPaint: {
                var ctx = getContext("2d")
                ctx.lineWidth = 1
                ctx.strokeStyle = root.color
                ctx.fillStyle = root.color
                ctx.font = '9pt sans-serif'
                ctx.beginPath()
                var nrows = height/50
                for(var i=0; i < nrows+1; i++){
                    ctx.moveTo(width, 50*i);
                    ctx.lineTo(width-10, 50*i);
                }

                var ncols = width/50
                for(var j=0; j < ncols+1; j++){
                    ctx.moveTo(50*j, 0);
                    ctx.lineTo(50*j, 10);
                }

                nrows = height/100
                for(i=0; i < nrows+1; i++){
                    ctx.moveTo(width, 100*i);
                    ctx.lineTo(width-20, 100*i);
                    ctx.fillText(String(100*i), width-30, 100*i)
                }

                ncols = width/50
                for(j=0; j < ncols+1; j++){
                    ctx.moveTo(100*j, 0);
                    ctx.lineTo(100*j, 20);
                    ctx.fillText(String(100*j), 100*j, 30)
                }
                ctx.closePath()
                ctx.stroke()
            }
        }

        Text{
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            text: parent.height
            color: root.color
            rotation: -90
        }
        Text{
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            text: parent.width
            color: root.color
        }
        Text{
            x: 10
            y: 10
            text: root.text
            color: root.color
            font.bold: true
        }
        Column{
            anchors.bottom: parent.bottom
            x: 10
            Text{
                id: colorTextItem
                visible: root.colorText
                text: (target.color ? target.color : "") + " " + (target.opacity ? target.opacity : "")
                color: root.color
                font.bold: true
            }
            Text{
                id: bottomTextItem
                text: root.bottomText
                color: root.color
                font.bold: true
            }
        }
    }


    Component.onCompleted: {
        var ignoreList = ["nulo", "underline"]
        var component

        function checkIgnore(_objectName){
            for(var objname in ignoreList)
            {
                if (objname === _objectName)
                    return false
            }
            return true
        }

        function finishCreation(){
            if (component.status === Component.Ready){
                var Q = []
                for(var i = 0; i < target.children.length; i++){
                    if (checkIgnore(target.children[i].objectName))
                        Q.push({item: target.children[i], recursive: root.recursive - 1})
                }
                while (Q.length != 0)
                {
                    var data = Q.pop()
                    if (data.recursive > 0)
                    {
                        for(i = 0; i < data.item.children.length; i++){
                            if (checkIgnore(data.item.children[i].objectName))
                                Q.push({item: data.item.children[i], recursive: data.recursive - 1})
                        }
                    }
                    component.createObject(data.item, {recursive: 0})
                }
            }
        }

        if (root.recursive > 0){
            component = Qt.createComponent("Nulo.qml")
            if (component.status === Component.Ready)
                finishCreation()
            else
                component.statusChanged.connect(finishCreation)
        }
    }
}


