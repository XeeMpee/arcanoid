import QtQuick 2.5
import QtQuick.Controls 2.11
import QtQuick.Layouts 1.14
import QtQuick.Controls.Material 2.12

import '../game/'

Page {
    anchors.fill: parent

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
            onClicked : {
                navigator.push(/* Some kind of routing? */)
            }
            Layout.alignment : menuLayout.menuAlignment
        }

        Container {
            Layout.fillHeight: true
            Layout.alignment : menuLayout.menuAlignment
        }

    }
}