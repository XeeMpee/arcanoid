import "../qml/game/"

import QtQuick 2.11
import QtQuick.Controls 2.12

Rectangle {
    id: root
    visible: true
    width: 1080
    height: 720

    StackView {
        anchors.fill: parent
        focus: true

        initialItem: Game{

        }
    }
    

}
