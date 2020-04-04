import QtQuick 2.5
import QtQuick.Controls 2.11
import QtQuick.Layouts 1.14
import QtQuick.Controls.Material 2.12

Page {
    header: Rectangle {
        height: 50
        color: Material.primary
    }
    
    ColumnLayout {
        id: menuLayout
        anchors.fill: parent
        anchors.margins: 50
        spacing: 20
        property int menuAlignment : Qt.AlignHCenter

        Label {
            text : "Arcanoid"
            font.pixelSize: 100
            Layout.alignment : menuLayout.menuAlignment
        }


        Button {
            text : "New Game"
            Layout.alignment : menuLayout.menuAlignment
            Layout.fillWidth: true

            onReleased : {
                navigator.push(navigator.routing.page("game/", navigator, {}))
            }
        }

        Button {
            text : "Options"
            Layout.alignment : menuLayout.menuAlignment
            Layout.fillWidth: true

            onClicked : {
                console.log("Options button clicked!");
                
            }
        }

        Container {
            Layout.fillHeight: true
            Layout.alignment : menuLayout.menuAlignment
        }

    }
}