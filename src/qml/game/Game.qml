import QtQuick 2.5
import QtQuick.Controls 2.11
import QtQuick.Layouts 1.14

import QtQuick.Controls.Material 2.12

import com.game.entities 1.0


Page {

    property var backendBoard : board
    property double transitionValue : 20
    
    header: Rectangle {
        height: 50
        color: Material.primary
    }

    Rectangle {
        id: boardItem
        height: 30
        radius: 10
        x:  backendBoard.x
        y:  backendBoard.y
        width: backendBoard.length
        gradient: Gradient {
            GradientStop { position: 0.0; color: Material.accent }
            GradientStop { position: 1.0; color: Material.primary }
        }
    }
    
    Keys.onPressed: {

        if (event.key == Qt.Key_Left) {
            console.log("move left");
            backendBoard.x -= transitionValue;
        }
        
        if (event.key == Qt.Key_Right) {
            console.log("move right");
            backendBoard.x += transitionValue;
        }

        if (event.key == Qt.Key_Up) {
            console.log("move up");
            backendBoard.y -= transitionValue;
        }

        if (event.key == Qt.Key_Down) {
            console.log("move down");
            backendBoard.y += transitionValue;
        }

        if (event.key == Qt.Key_Space) {
            console.log("ball starts");
        }
    } 

    Component.onCompleted : {
        game.run()
        console.log("Game page loaded...")
    }
}