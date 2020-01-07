import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import Observer.Pattern 1.0



Window {
    id: window
    visible: true
    title: qsTr("Observer")
    width: 640
    height: 300
    minimumHeight: 220
    minimumWidth: 470



    Displacement {
        id: displacement
        onDisplacementChanged: function()
        {
            speed.setValue(displacement.value);
            previousDisplacementLabel3.text = previousDisplacementLabel2.text;
            previousDisplacementLabel2.text = previousDisplacementLabel1.text;
            previousDisplacementLabel1.text = displacement.value;
        }
    }

    Speed {
        id: speed
        onSpeedChanged: acceleration.setValue(speed.value);
    }

    Acceleration {
        id: acceleration
    }


    Column {
        id: column
        width: window.width * 0.3
        height: 300
        anchors.right: parent.right
        anchors.rightMargin: 0

        Label {
            id: label
            text: qsTr("Last Displacements")
        }

        Label {
            id: previousDisplacementLabel1
            anchors.topMargin: 0

        }

        Label {
            id: previousDisplacementLabel2
            anchors.topMargin: 0
        }

        Label {
            id: previousDisplacementLabel3
            anchors.topMargin: 0
        }

    }

    Rectangle {
        id: row1
        width: window.width * 0.7
        height: window.height / 3
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0

        Rectangle {
            id: column1
            width: parent.width / 3
            height: parent.height
            anchors.left: parent.left
            anchors.leftMargin: 0

            Label {
                id: displacementLabel
                text: qsTr("Displacement")
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }
        }


        Rectangle {
            id: column2

            width: parent.width / 3
            height: parent.height
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: -2

            TextField {
                id: textField
                width: parent.width
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                transformOrigin: Item.Center
                placeholderText: qsTr("")
            }
        }

        Rectangle {
            id: column3

            width: parent.width / 3
            height: parent.height
            anchors.right: parent.right
            anchors.rightMargin: 0

            Button {
                id: button
                text: qsTr("Change")
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                width: parent.width * 0.5

                contentItem: Text {
                    text: button.text
                    color: "white"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }

                background: Rectangle{
                    id: buttonBackground
                    color: "grey"
                    anchors.fill: parent
                }

                MouseArea {
                    id: mouseArea1
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: buttonBackground.color = "black"
                    onExited: buttonBackground.color = "grey"
                    onClicked: function() {
                        if(textField.text != "")
                            displacement.setDisplacement(parseInt(textField.text));
                        textField.clear();
                    }
                }
            }
        }

    }

    Rectangle {
        id: row2
        width: window.width * 0.7
        height: window.height / 3
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.verticalCenter: parent.verticalCenter

        Rectangle {
            id: column4
            width: parent.width / 2
            height: parent.height
            anchors.leftMargin: 0
            anchors.left: parent.left

            Label {
                id: speedLabel
                x: 0
                y: 0
                text: qsTr("Speed")
                anchors.right: parent.right
                anchors.rightMargin: 0
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        Rectangle {
            id: column5
            width: parent.width / 2
            height: parent.height
            anchors.right: parent.right
            anchors.rightMargin: 0

            Label {
                id: speedValueLabel

                text: speed.value;
                anchors.left: parent.left
                anchors.leftMargin: parent.width * 0.1
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }

    Rectangle {
        id: row3
        width: window.width * 0.7
        height: window.height / 3
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0


        Rectangle {
            id: column6
            width: parent.width / 2
            height: parent.height
            anchors.leftMargin: 0
            anchors.left: parent.left

            Label {
                id: accelerationVLabel

                text: qsTr("Acceleration")
                anchors.right: parent.right
                anchors.rightMargin: 0
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        Rectangle {
            id: column7
            width: parent.width / 2
            height: parent.height
            anchors.right: parent.right
            anchors.rightMargin: 0

            Label {
                id: accelerationValueLabel

                text: acceleration.value;
                anchors.left: parent.left
                anchors.leftMargin: parent.width * 0.1
                anchors.verticalCenter: parent.verticalCenter
            }
        }

    }

}

