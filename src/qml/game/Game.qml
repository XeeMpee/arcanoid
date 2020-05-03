import QtQuick 2.5
import QtQuick.Controls 2.11
import QtQuick.Layouts 1.14

import QtQuick.Controls.Material 2.12


Page {
    header: Rectangle {
        height: 50
        color: Material.primary
    }

    
    Rectangle {
        anchors.centerIn: parent
        width: 50
        height: 50
        color: "red"
    }

    Component.onCompleted : {
        game.run()
        console.log("Game page loaded...")
    }
}