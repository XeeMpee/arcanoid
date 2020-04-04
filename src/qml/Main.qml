import "routing/Routing.js" as R;

import QtQuick 2.11
import QtQuick.Controls 2.12

Rectangle {
    id: root
    visible: true
    width: 1080
    height: 720

    StackView {
        property var routing : new R.Routing (
            [
                new R.RoutingElement("menu/", 'qrc:/qml/game_menu/GameMenu.qml'),
                new R.RoutingElement("game/", 'qrc:/qml/game/Game.qml')
            ]
        )

        // StackView basic properties:
        id: navigator
        anchors.fill: parent
        focus: true
        initialItem: routing.page("menu/", navigator, {})


        // StackView transition animations:
        pushEnter: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 0
                to:1
                duration: 400
            }
        }
        pushExit: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 1
                to:0
                duration: 400
            }
        }
    }
}
