import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import Observer.Pattern 1.0



Window {
    visible: true
    title: qsTr("Observer")
    width: 640
    height: 300



    Displacement {
        id: displacement
        onDisplacementChanged: speed.setValue(displacement.value)
    }

    Speed {
        id: speed
        onSpeedChanged: acceleration.setValue(speed.value);
    }

    Acceleration {
        id: acceleration
    }

    Row {
        id: row
        x: 0
        y: 57
        width: 640
        height: 65

        TextField {
            id: textField
            x: 153
            y: 69
        }

        Button {
            id: button
            x: 404
            y: 70
            text: qsTr("Change")
            onClicked: function() {
                displacement.setDisplacement(parseInt(textField.text));
                textField.clear();
            }
        }

        Label {
            id: label
            x: 48
            y: 81
            text: qsTr("Displacement")
        }
    }

    Row {
        id: row1
        x: -6
        y: 128
        width: 640
        height: 65

        Label {
            id: label1
            x: 48
            y: 152
            text: qsTr("Speed")
        }

        Label {
            id: label2
            x: 153
            y: 152
            text: speed.value;
        }
    }

    Row {
        id: row2
        x: 0
        y: 199
        width: 640
        height: 65


        Label {
            id: label3
            x: 48
            y: 223
            text: qsTr("Acceleration")
        }

        Label {
            id: label4
            x: 153
            y: 223
            text: acceleration.value;
        }
    }
}
