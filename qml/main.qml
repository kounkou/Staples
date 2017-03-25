import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick 2.7
import QtQuick.Window 2.0

ApplicationWindow {
    id: window
    visible: true
    width :Screen.width
    height:Screen.height
    title: qsTr("Staples")

    Rectangle {
        id : header
        width: parent.width
        height: 200
        border.width: 1
        border.color: "lightgrey"

        Text {
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.fill: parent
            text: "Staples"
            font.bold: true
            font.pointSize: 20
            elide: Text.ElideMiddle
            color: "#212121"
        }
    }

    Rectangle {
        width : window.width
        height: window.height - header.height

        anchors.top : header.bottom
        anchors.topMargin: 0

        color: "white"
        clip: true

        Component {
            id: contactDelegate

            Rectangle {
                id: box
                height:150
                width: parent.width
                color: "white"
                border.width: 1
                border.color: "lightgrey"

                anchors.leftMargin  : 20
                anchors.rightMargin : 20
                anchors.bottomMargin: 20

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
                    color: "#212121"
                    font.pointSize: 15
                    font.bold : true
                    anchors.left      : box.left
                    anchors.leftMargin: 10
                    anchors.top       : box.top
                    anchors.topMargin : 5
                }

                Label {
                    id: staplePrice
                    font.pointSize: 13
                    text: "Product costs €" + Math.round(price * 100) / 100
                    color: "#424242"
                    anchors.left        : box.left
                    anchors.leftMargin  : 10
                    anchors.top         : stapleName.bottom
                    anchors.topMargin   : 5
                }

                Label {
                    id: stapleExpirationDate
                    font.pointSize: 13
                    wrapMode: Text.WordWrap
                    text: "This product will expire on " + numberOfDaysBeforeExpiration +
                          "<br> according to Staples calculations."
                    color: "#9e9e9e"
                    anchors.left        : box.left
                    anchors.leftMargin  : 10
                    anchors.top         : staplePrice.bottom
                    anchors.topMargin   : 5
                    anchors.bottomMargin: 5
                }

                Rectangle {
                    id: stapleQuantity

                    Label {
                        font.pointSize: 10
                        text: quantity
                        color: "#ffffff"
                        anchors.centerIn: stapleQuantity
                    }

                    height: stapleImage.height/2
                    width: stapleImage.width/2
                    color: quantity > 2 ? "#00c853" : "#dd2c00"
                    radius: stapleImage.height/4

                    anchors.right: stapleImage.left
                    anchors.verticalCenter: box.verticalCenter
                    anchors.rightMargin: -10
                    z : 1
                    anchors.bottomMargin: 10
                }

                Image {
                    id: stapleImage
                    anchors.right: box.right
                    anchors.rightMargin: 10
                    width: box.height/2
                    height: box.height/2
                    anchors.verticalCenter: box.verticalCenter
                    source: "qrc:/raw-food.svg"
                }
            }
        }

        ListView {
            id:contactList
            anchors.fill: parent
            model: stapleModel
            delegate: contactDelegate
            spacing: 0
            focus: false
        }
    }
}
