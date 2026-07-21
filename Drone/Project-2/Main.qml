import QtQuick
import QtQuick.Controls

ApplicationWindow {

    width: 500
    height: 250
    visible: true

    title: "PX4 Ground Station"

    Column {

        anchors.centerIn: parent
        spacing: 20

        Text {

            text: "PX4 Ground Station"

            font.pixelSize: 24
        }

        Text {

            text: drone.connected
                    ? "Connected"
                    : "Waiting for PX4..."

            font.pixelSize: 18
        }
    }
}
