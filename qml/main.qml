import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick 2.7
import QtQuick.Window 2.0

ApplicationWindow {
    id: window
    visible: true
    width :Screen.width
    height:Screen.height
    title: qsTr("Stapples")

    Rectangle {
        width : window.width
        height: window.height

        anchors.top : window.top
        anchors.topMargin: 100
        anchors.centerIn: parent

        color: "white"

        Component {
            id: contactDelegate

            Rectangle {
                id: box
                height:100
                width: parent.width
                color: "lightsteelblue"
                border.width: 2
                border.color: "lightgrey"

                anchors.leftMargin  : 20
                anchors.rightMargin : 20
                anchors.topMargin   : 20
                anchors.bottomMargin: 20

                radius: 5

                Component.onCompleted: {
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                    }
                }

                Label {
                    id: stapleName
                    text: name
                    font.pointSize: 15
                    anchors.top: parent.top
                    anchors.topMargin: 5
                    anchors.leftMargin: 5
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Label {
                    id: staplePrice
                    font.pointSize: 15
                    text: '€' + Math.round(price * 100) / 100
                    anchors.centerIn: parent
                }

                Label {
                    id: stapleExpirationDate
                    font.pointSize: 15
                    text: numberOfDaysBeforeExpiration
                    anchors.bottom: box.bottom
                    anchors.bottomMargin: 5
                    anchors.leftMargin: 5
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }

        ListView {
            id:contactList
            anchors.fill: parent
            model: stapleModel
            delegate: contactDelegate

            highlight: Rectangle {
                color: "lightgrey"
                radius: 5
            }

            spacing: 5
            focus: false
        }
    }
}
