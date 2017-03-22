import QtQuick 2.6
import QtWebView 1.1

Rectangle {
    property alias textEdit: textEdit

    width: 360
    height: 360

    TextEdit {
        id: textEdit
        text: qsTr("Enter some text...")
        verticalAlignment: Text.AlignVCenter
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        Rectangle {
            anchors.fill: parent
            anchors.margins: -10
            color: "transparent"
            border.width: 1
        }
    }

    Image{
        anchors.top: textEdit.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        width: 900
        height: 900

        source: "image://QrCodeImgProvider/yellow"
    }
}
