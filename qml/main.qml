import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick 2.7
import QtQuick.Window 2.0
import QtQuick.Controls.Material 2.0

Rectangle {
    id: window
    visible: true
    width :Screen.width
    height:Screen.height

    signal refresh()
    signal searchStaple(string name)
    signal authentificate(string username, string password)
    signal addStaple(string expirationDate, string name, double price, int qty)
    signal addOneStaple(string name)
    signal removeOneStaple(string name)
    signal removeStaple(string name)

    property real boxHeight : 180
    property bool needFresh : false

    Rectangle {
        width : window.width
        height: window.height
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
                    PropertyChanges { target: removerAll;     visible: true }
                    PropertyChanges { target: removerOne;     visible: true }
                    PropertyChanges { target: adderOne;       visible: true }
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

                /*
                ListView.onAdd: SequentialAnimation {
                    PropertyAction  { target: box; property: "height";  value: 0 }
                    NumberAnimation { target: box; property: "height";  to: boxHeight; duration: 250; easing.type: Easing.InOutQuad }
                }
                ListView.onRemove: SequentialAnimation {
                    PropertyAction  { target: box;  property: "ListView.delayRemove"; value: true }
                    NumberAnimation { target: box; property: "height"; to: 0; duration: 250; easing.type: Easing.InOutQuad }

                    // Make sure delayRemove is set back to false so that the item can be destroyed
                    PropertyAction { target: box; property: "ListView.delayRemove"; value: false }
                }
                */

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
                    font.family: "Helvetica"
                    font.bold : true
                    anchors.left      : box.left
                    anchors.leftMargin: 16
                    anchors.top       : box.top
                    anchors.topMargin : 5
                }

                Label {
                    id: staplePrice
                    font.pointSize: 13
                    font.family: "Helvetica"
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
                    font.family: "Helvetica"
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
                    height: boxHeight/3
                    width: boxHeight/3
                    color: quantity > 0 ? "#00c853" : "grey"
                    radius: boxHeight/32
                    anchors.right: box.right
                    anchors.verticalCenter: box.verticalCenter
                    anchors.rightMargin: 16
                    anchors.bottomMargin: 16
                }

                Image {
                    id : adderOne
                    anchors.horizontalCenter: box.horizontalCenter
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 5
                    source: "qrc:/add.png"
                    height: boxHeight/2.5
                    width: boxHeight/2.5
                    visible: false
                    opacity: 0.5

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                           addOneStaple(name)
                        }
                        onPressed:  { adderOne.state = "PRESSED" }
                        onReleased: { adderOne.state = "RELEASED" }
                    }

                    states: [
                        State { name: "PRESSED"; PropertyChanges  { target: adderOne; opacity: 1.0}},
                        State { name: "RELEASED"; PropertyChanges { target: adderOne; opacity: 0.5}}
                    ]
                }

                Image {
                    id : removerOne
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 5
                    anchors.right: adderOne.left
                    anchors.rightMargin: 40
                    source: "qrc:/deleteOne.png"
                    height: boxHeight/2.5
                    width: boxHeight/2.5
                    visible: false
                    opacity: 0.5

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                           removeOneStaple(name)
                        }
                        onPressed:  { removerOne.state = "PRESSED" }
                        onReleased: { removerOne.state = "RELEASED" }
                    }

                    states: [
                        State { name: "PRESSED"; PropertyChanges  { target: removerOne; opacity: 1.0}},
                        State { name: "RELEASED"; PropertyChanges { target: removerOne; opacity: 0.5}}
                    ]
                }

                Image {
                    id : removerAll
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 5
                    anchors.left: adderOne.right
                    anchors.leftMargin: 40
                    source: "qrc:/deleteAll.png"
                    height: boxHeight/2.5
                    width: boxHeight/2.5
                    visible: false
                    opacity: 0.5

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                           removeStaple(name)
                        }

                        onPressed:  { removerAll.state = "PRESSED" }
                        onReleased: { removerAll.state = "RELEASED" }
                    }

                    states: [
                        State { name: "PRESSED"; PropertyChanges  { target: removerAll; opacity: 1.0}},
                        State { name: "RELEASED"; PropertyChanges { target: removerAll; opacity: 0.5}}
                    ]
                }
            }
        }

        ListView {
            id:contactList
            anchors.fill: parent
            model: stapleModel
            delegate: contactDelegate
            spacing: -1
            focus: true

            snapMode: ListView.SnapToItem
            headerPositioning: ListView.InlineHeader

            header: Rectangle {
                id : header
                width: parent.width
                height: Screen.height/3
                Material.elevation: 0

                Image {
                    id: staplesImage
                    source: "qrc:/olive-oil.jpg"
                    anchors.fill: parent
                    fillMode: Image.PreserveAspectCrop
                }

                TextField {
                    id : txtFld
                    width : header.width - 40
                    height: header.height/5
                    Material.elevation: 10
                    color: "#424242"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: header.top
                    anchors.topMargin: 10
                    smooth: true
                    placeholderText: "house-hold staple"
                    padding: search.width + 10
                    clip: true
                    font.pointSize: 15
                    font.bold: false
                    font.family: "Helvetica"

                    onEditingFinished: {
                        searchStaple(txtFld.text)
                        // txtFld.text = ""
                    }

                    background: Rectangle {
                        color: "#ffffff"
                        radius: 5
                        anchors.leftMargin: 5
                    }

                    Image {
                        id: search
                        anchors {
                            top: txtFld.top;
                            left: txtFld.left;
                        }
                        smooth: true
                        fillMode: Image.PreserveAspectFit
                        source: "qrc:/search.png"
                        height: txtFld.height - 25
                        width : txtFld.height - 25
                        anchors.verticalCenter: txtFld.verticalCenter
                        opacity: 0.5
                    }
                }
            }

            // refresh the list of pull
            onContentYChanged:
            {
                // console.log(contentY)

                if (contentY < -100)
                {
                    // console.log(contentY)
                    // console.log("staples will be refresh on release")
                    needFresh = true
                }
            }

            onDragEnded:
            {
                if (needFresh == true)
                {
                    needFresh = false
                    // refresh()
                }
            }
        }
    }
}
