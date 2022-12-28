import QtQuick 2.0

Item {
    id: container
    width: sizeImageFolder * 2; height: sizeImageFolder * 2
    property color color

    // select Sequential or Sprite
    property bool isSequentialLoading: true
    property int sizeImageFolder: 40

    // for Sequential
    property string prefixImageLoading: "loop"
    property int numberFrames: 30
    property int duration: 1000

    // for Sprite
    property string source: "../image/loop/loading_loop29.png"

    function start() {
        animation.restart()
        animation.running = true
    }

    function stop() {
        animation.stop()
        animation.running = false
    }

    Image {
        id: svgOverlay
        property int currImage: 0
        width: sizeImageFolder * 2
        height: sizeImageFolder * 2
        source: "../image/" + prefixImageLoading + "/loading_" + prefixImageLoading + ("00" + currImage).slice(-2) + ".png"

        SequentialAnimation on currImage{
            id: animation
            running: false

            PropertyAnimation {
                loops: 3//Animation.Infinite
                from: 0; to: numberFrames - 1
                duration: container.duration
            }
        }
    }
}
