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
        y:  backendBoard.x
        width: backendBoard.length
        color: "red"
    }
    
    Keys.onPressed: {
        //TODO:  backendBoard insted boardItem properties should be changed! 
        if (event.key == Qt.Key_Left) {
            console.log("move left");
            boardItem.x -= 5;
        }
        
        if (event.key == Qt.Key_Right) {
            console.log("move right");
            boardItem.x += 5;
        }

        if (event.key == Qt.Key_Up) {
            console.log("move up");
            boardItem.y -= 5;
        }

        if (event.key == Qt.Key_Down) {
            console.log("move down");
            boardItem.y += 5;
        }
    } 

    Component.onCompleted : {
        game.run()
        console.log("Game page loaded...")
    }
}