import QtQuick 2.0
import "../image"

Item {
    width: 90; height: 90
    function start() {
        animation.restart()
    }

    Image {
        anchors.centerIn: parent
        property int currImage: 0
        source: "../image/loop/loading_loop" +
                (currImage < 10 ? "0" + currImage : currImage) + ".png" //"../image/loop/loading_loop00.png"

        SequentialAnimation on currImage{
            id: animation
            running: false

            PropertyAnimation {
                loops: 1
                from: 0; to: 29
                duration: 1000
            }
        }
    }
}
