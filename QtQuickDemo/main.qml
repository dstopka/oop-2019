import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import observer.displacement 1.0
import observer.acceleration 1.0
import observer.speed 1.0


Window {
    visible: true
    title: qsTr("Hello World")
    width: 640
    height: 640



    Displacement {
        id: displacement
        onDisplacementChanged: speed.setSpeed(displacement.value)
    }

    Speed {
        id: speed
        onChanged: acceleration.setAcc(speed.value);
    }

    Acceleration {
        id: acceleration
    }

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
        }
    }

    Label {
        id: label
        x: 48
        y: 81
        text: qsTr("Displacement")
    }

    Label {
        id: label1
        x: 48
        y: 183
        text: qsTr("Speed")
    }

    Label {
        id: label2
        x: 235
        y: 183
        text: speed.value;
    }

    Label {
        id: label3
        x: 48
        y: 232
        text: qsTr("Acceleration")
    }

    Label {
        id: label4
        x: 235
        y: 232
        text: acceleration.value;
    }
}
