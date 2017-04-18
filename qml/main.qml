import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick 2.7
import QtQuick.Window 2.0
import QtQuick.Controls.Material 2.0

ApplicationWindow {
    id: window
    visible: true
    width :Screen.width
    height:Screen.height
    title: qsTr("Staples")

    signal          refresh()
    property real   boxHeight      : 180

    Rectangle {
        id : header
        width: parent.width
        height: Screen.height/3
        Material.elevation: 10

        Image {
            id: staplesImage
            source: "qrc:/olive-oil.jpg"
            anchors.fill: parent
            fillMode: Image.PreserveAspectCrop
        }
    }

    Rectangle {
        width : window.width
        height: window.height - header.height

        anchors.top : header.bottom
        anchors.topMargin: 0

        color: "#f5f5f5"
        clip: true

        Component {
            id: contactDelegate

            Rectangle {
                id: box
                height:boxHeight
                width: parent.width
                color: "white"
                border.width: 1
                border.color: "lightgrey"

                anchors.leftMargin  : 16
                anchors.rightMargin : 16
                anchors.bottomMargin: 20

                states: State {
                    name: "Details"
                    PropertyChanges { target: box;            height: boxHeight*2 }
                    PropertyChanges { target: stapleQuantity; visible: true }
                    //PropertyChanges { target: stapleImage;    visible: true }
                }

                transitions: Transition {
                    ParallelAnimation {
                        NumberAnimation {
                            duration: 300
                            properties: "height"
                            easing {
                                type:  Easing.InOutQuart
                                amplitude: 1.0
                                period: 0.5
                            }
                        }
                    }
                }

                ListView.onAdd: SequentialAnimation {
                    PropertyAction  { target:  box; property: "height"; value: 0 }
                    NumberAnimation { target: box; property: "height"; to: boxHeight; duration: 250; easing.type: Easing.InOutQuad }
                }
                ListView.onRemove: SequentialAnimation {
                    PropertyAction  { target: box;  property: "ListView.delayRemove"; value: true }
                    NumberAnimation { target: box; property: "height"; to: 0; duration: 250; easing.type: Easing.InOutQuad }

                    // Make sure delayRemove is set back to false so that the item can be destroyed
                    PropertyAction { target: box; property: "ListView.delayRemove"; value: false }
                }

                Behavior on height
                {
                    NumberAnimation
                    {
                        property   : "height";
                        duration   : 300;
                        easing.type: Easing.OutBack
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        if   (box.state == "") { box.state = "Details" }
                        else                   { box.state = "" }

                        // console.log(expirationDate.toString())
                    }
                }

                Label {
                    id: stapleName
                    text: name
                    color: "#424242"
                    font.pointSize: 15
                    font.bold : true
                    anchors.left      : box.left
                    anchors.leftMargin: 16
                    anchors.top       : box.top
                    anchors.topMargin : 5
                }

                Label {
                    id: staplePrice
                    font.pointSize: 13
                    text: qsTr("Product costs €") + Math.round(price * 100) / 100
                    color: "#424242"
                    anchors.left        : box.left
                    anchors.leftMargin  : 16
                    anchors.top         : stapleName.bottom
                    anchors.topMargin   : 5
                }

                Label {
                    id: stapleExpirationDate

                    property date   expDate        : new Date(expirationDate)
                    property string dateTimeString : expDate.toLocaleDateString()

                    font.pointSize: 13
                    wrapMode: Text.WordWrap
                    text: qsTr("This product will expire on <br>") + Date.fromLocaleDateString(dateTimeString) +
                          qsTr("<br> according to Staples calculations.")
                    color: "#9e9e9e"
                    anchors.left        : box.left
                    anchors.leftMargin  : 16
                    anchors.top         : staplePrice.bottom
                    anchors.topMargin   : 5
                    anchors.bottomMargin: 5
                }

                Rectangle {
                    id: stapleQuantity

                    Label {
                        font.pointSize: 15
                        text: quantity
                        color: "#ffffff"
                        anchors.centerIn: stapleQuantity
                    }
                    height: box.height/3
                    width: box.height/3
                    color: quantity > 0 ? "#00c853" : "grey"
                    radius: box.height/32
                    anchors.right: box.right
                    anchors.verticalCenter: box.verticalCenter
                    anchors.rightMargin: 16
                    anchors.bottomMargin: 16
                    z : 1
                }

                /*
                Image {
                    id: stapleImage
                    anchors.right: box.right
                    anchors.rightMargin: 10
                    width: 75
                    height: 75
                    anchors.verticalCenter: box.verticalCenter
                    source: "qrc:/raw-food.svg"
                }
                */
            }
        }

        ListView {
            id:contactList
            anchors.fill: parent
            model: stapleModel
            delegate: contactDelegate
            spacing: -1
            focus: true

            // refresh the list of pull
            onDragEnded: {
                console.log("refreshing the list of staples...")
                refresh()
            }
        }
    }
}
