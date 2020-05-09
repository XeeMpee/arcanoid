import QtQuick 2.5
import QtQuick.Controls 2.11
import QtQuick.Layouts 1.14

import QtQuick.Controls.Material 2.12

import com.game.entities 1.0


Page {

    property var backendBoard : board
    
    header: Rectangle {
        height: 50
        color: Material.primary
    }

    Rectangle {
        id: boardItem
        height: 10
        x:  backendBoard.x
        y:  backendBoard.y
        width: backendBoard.length
        color: "red"
    }
    
    Keys.onPressed: {

        if (event.key == Qt.Key_Left) {
            console.log("move left");
            backendBoard.x -= 5;
        }
        
        if (event.key == Qt.Key_Right) {
            console.log("move right");
            backendBoard.x += 5;
        }

        if (event.key == Qt.Key_Up) {
            console.log("move up");
            backendBoard.y -= 5;
        }

        if (event.key == Qt.Key_Down) {
            console.log("move down");
            backendBoard.y += 5;
        }
    } 

    Component.onCompleted : {
        game.run()
        console.log("Game page loaded...")
    }
}