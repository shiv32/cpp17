import QtQuick 2.9
import QtQuick.Controls 2.2

import CustomPdf 1.0

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "PDF Viewer (Qt 5 + Poppler)"

    PdfItem {
        id: viewer
        anchors.fill: parent
        filePath: "../sample.pdf"
        pageNum: 0
        antialiasing: true
    }

    Button {
        id:nextBtn
        text: "Next Page"
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        enabled: viewer.pageNum < viewer.pageCount - 1
        onClicked: viewer.pageNum += 1
    }

    Button {
        id:backBtn
        text: "Back Page"
        anchors.bottom: parent.bottom
        anchors.right:   nextBtn.left
        anchors.rightMargin: 10
        enabled: viewer.pageNum != 0
        onClicked: {
            viewer.pageNum -= 1
        }
    }
}
