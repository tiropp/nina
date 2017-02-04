import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4

Item {
    id: invoiceForm
    width: 800
    height: 1200
    property alias btnLoad: btnLoad
    property alias btnSave: btnSave
    anchors.fill: parent

    property alias invoiceForm: invoiceForm
    property alias recvUsePoBox: recvUsePoBox
    property alias recvZipCode: recvZipCode
    property alias recvCountry: recvCountry
    property alias senderCountry: senderCountry
    property alias positionSkip: positionSkip
    property alias fontSkip: fontSkip
    property alias fontSize: fontSize
    property alias signature: signature
    property alias greetings: greetings
    property alias title: title
    property alias bankAccount: bankAccount
    property alias bankBic: bankBic
    property alias bankName: bankName
    property alias dateYear: dateYear
    property alias dateMonth: dateMonth
    property alias dateDay: dateDay
    property alias useDateSpcified: useDateSpcified
    property alias useDateToday: useDateToday
    property alias textAfterPositions: textAfterPositions
    property alias textBeforePositions: textBeforePositions
    property alias senderPhoneInBottomLine: senderPhoneInBottomLine
    property alias recvPlace: recvPlace
    property alias recvStreet: recvStreet
    property alias recvCompany: recvCompany
    property alias recvName: recvName
    property alias recvSalutation: recvSalutation
    property alias senderMobilePhone: senderMobilePhone
    property alias senderPhone: senderPhone
    property alias btnDeletePos: btnDeletePos
    property alias btnModifyPos: btnModifyPos
    property alias btnNewPos: btnNewPos
    property alias senderName: senderName
    property alias senderCompany: senderCompany
    property alias senderStreet: senderStreet
    property alias senderZipCode: senderZipCode
    property alias senderPlace: senderPlace
    property alias btnCreatePdf: btnCreatePdf
    property alias positions: positions

    Page {
        id: page
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        GroupBox {
            id: sender
            x: 10
            y: 10
            width: 281
            height: 267
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.topMargin: 10
            title: qsTr("Absender")

            TextField {
                id: senderName
                x: 57
                y: 5
                width: 200
                height: 25
                text: qsTr("")
            }

            TextField {
                id: senderCompany
                x: 57
                y: 30
                width: 200
                height: 25
                text: qsTr("")
            }

            TextField {
                id: senderStreet
                x: 57
                y: 55
                width: 200
                height: 25
                text: qsTr("")
            }

            TextField {
                id: senderZipCode
                x: 57
                y: 80
                width: 50
                height: 25
                text: qsTr("")
            }

            TextField {
                id: senderPlace
                x: 107
                y: 80
                width: 150
                height: 25
                text: qsTr("")
            }

            TextField {
                id: senderPhone
                x: 57
                y: 106
                width: 200
                height: 25
                text: qsTr("")
            }

            TextField {
                id: senderMobilePhone
                x: 57
                y: 132
                width: 200
                height: 25
                text: qsTr("")
            }

            TextField {
                id: senderCountry
                x: 57
                y: 157
                width: 200
                height: 25
                text: qsTr("")
            }

            CheckBox {
                id: senderPhoneInBottomLine
                x: 0
                y: 188
                text: qsTr("Telefon, Natel in Bottom-Line")
            }

            Label {
                id: label4
                x: 0
                y: 86
                text: qsTr("PLZ/Ort")
            }

            Label {
                id: label3
                x: 0
                y: 61
                text: qsTr("Strasse")
            }

            Label {
                id: label2
                x: 0
                y: 36
                text: qsTr("Firma")
            }

            Label {
                id: label1
                x: 0
                y: 11
                text: qsTr("Name")
            }

            Label {
                id: label5
                x: 0
                y: 112
                text: qsTr("Telefon")
            }

            Label {
                id: label11
                x: 0
                y: 138
                text: qsTr("Natel")
            }

            Label {
                id: label23
                x: 0
                y: 163
                text: qsTr("Land")
            }
        }

        GroupBox {
            id: receiver
            x: 297
            y: 10
            width: 276
            height: 233
            z: 2
            anchors.top: parent.top
            anchors.topMargin: 10
            title: qsTr("Anschrift")

            TextField {
                id: recvSalutation
                x: 52
                y: -7
                width: 200
                height: 25
                text: qsTr("")
            }

            TextField {
                id: recvName
                x: 52
                y: 18
                width: 200
                height: 25
                text: qsTr("")
            }

            TextField {
                id: recvCompany
                x: 52
                y: 43
                width: 200
                height: 25
                text: qsTr("")
            }

            TextField {
                id: recvStreet
                x: 52
                y: 68
                width: 200
                height: 25
                text: qsTr("")
            }

            TextField {
                id: recvZipCode
                x: 52
                y: 93
                width: 50
                height: 25
                text: qsTr("")
            }

            TextField {
                id: recvPlace
                x: 102
                y: 93
                width: 150
                height: 25
                text: qsTr("")
            }

            TextField {
                id: recvCountry
                x: 52
                y: 118
                width: 200
                height: 25
                text: qsTr("")
            }

            CheckBox {
                id: recvUsePoBox
                x: -1
                y: 149
                text: qsTr("Postfach")
            }

            Label {
                id: label10
                x: -1
                y: -1
                text: qsTr("Andrede")
            }

            Label {
                id: label9
                x: -1
                y: 99
                text: qsTr("PLZ/Ort")
            }

            Label {
                id: label8
                x: -1
                y: 74
                text: qsTr("Strasse")
            }

            Label {
                id: label7
                x: -1
                y: 49
                text: qsTr("Firma")
            }

            Label {
                id: label6
                x: -1
                y: 24
                text: qsTr("Name")
            }

            Label {
                id: label24
                x: -1
                y: 124
                text: qsTr("Land")
            }
        }

        GroupBox {
            id: fontSettings
            x: 376
            width: 241
            height: 183
            anchors.top: bank.bottom
            anchors.topMargin: 5
            title: qsTr("Schriftgrösse")

            TextField {
                id: positionSkip
                x: 136
                y: -862
                width: 60
                height: 40
                text: "12"
                anchors.top: parent.top
                anchors.topMargin: 92
                placeholderText: qsTr("")
            }

            TextField {
                id: fontSkip
                x: 136
                y: 46
                width: 60
                height: 40
                text: "12"
                placeholderText: qsTr("")
            }

            TextField {
                id: fontSize
                x: 136
                width: 60
                height: 40
                text: "12"
                anchors.top: parent.top
                anchors.topMargin: 0
                placeholderText: qsTr("")
            }

            Label {
                id: label22
                x: -3
                y: 83
                width: 122
                height: 58
                text: qsTr("zusätzlicher Abstand zwischen den einzelnen Positionen")
                wrapMode: Text.WordWrap
            }

            Label {
                id: label21
                x: 0
                y: 59
                text: qsTr("Schriftabstand")
            }

            Label {
                id: label20
                text: qsTr("Schriftgrösse")
                anchors.top: parent.top
                anchors.topMargin: 13
                anchors.left: parent.left
                anchors.leftMargin: 0
            }

            Label {
                id: label25
                x: 207
                y: 13
                text: qsTr("pt")
            }

            Label {
                id: label26
                x: 207
                y: 59
                text: qsTr("pt")
            }

            Label {
                id: label27
                x: 207
                y: 105
                text: qsTr("pt")
            }
        }

        GroupBox {
            id: grpPositions
            x: 10
            height: 285
            anchors.top: sender.bottom
            anchors.topMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.left: parent.left
            anchors.leftMargin: 10
            title: qsTr("Positionen")

            TableView {
                id: positions
                height: 192
                anchors.right: parent.right
                anchors.left: parent.left
                anchors.top: parent.top
                model: positionContainerModel

                TableViewColumn {
                    role: "description"
                    title: qsTr("Beschreibung")
                    width: 400
                }
                TableViewColumn {
                    role: "unit"
                    title: qsTr("Art")
                    width: 100
                }
                TableViewColumn {
                    role: "numUnits"
                    title: qsTr("Anzahl")
                    width: 100
                }
                TableViewColumn {
                    role: "pricePerUnit"
                    title: qsTr("Fr./Art")
                    width: 100
                }
            }

            Button {
                id: btnNewPos
                y: 181
                text: qsTr("Neue Position")
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
            }

            Button {
                id: btnModifyPos
                y: 181
                text: qsTr("Ändern")
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                anchors.left: parent.left
                anchors.leftMargin: 106
            }

            Button {
                id: btnDeletePos
                y: 181
                text: qsTr("Entfernen")
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                anchors.left: parent.left
                anchors.leftMargin: 212
            }
        }

        GroupBox {
            id: bank
            x: 376
            width: 360
            height: 177
            anchors.top: texte.bottom
            anchors.topMargin: 5
            title: qsTr("Bankverbindung")

            Label {
                id: label17
                y: 9
                text: qsTr("Bankname")
                anchors.left: parent.left
                anchors.leftMargin: 0
            }

            Label {
                id: label18
                y: 55
                text: qsTr("BLZ")
                anchors.left: parent.left
                anchors.leftMargin: 0
            }

            Label {
                id: label19
                y: 101
                text: qsTr("Konto Nr.")
                anchors.left: parent.left
                anchors.leftMargin: 0
            }

            TextField {
                id: bankName
                x: 83
                width: 262
                height: 40
                anchors.top: parent.top
                anchors.topMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 0
                placeholderText: qsTr("")
            }

            TextField {
                id: bankBic
                x: 74
                y: 46
                width: 262
                height: 40
                anchors.right: parent.right
                anchors.rightMargin: 0
                placeholderText: qsTr("")
            }

            TextField {
                id: bankAccount
                x: 74
                y: 92
                width: 262
                height: 40
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 0
                placeholderText: qsTr("")
            }
        }

        GroupBox {
            id: misc
            x: 10
            width: 360
            height: 202
            anchors.top: dates.bottom
            anchors.topMargin: 5
            title: qsTr("Sonstiges")

            Label {
                id: label13
                x: 0
                y: 13
                text: qsTr("Titel")
            }

            TextField {
                id: title
                x: 93
                y: 0
                width: 243
                height: 40
                text: "Rechnung"
                placeholderText: qsTr("")
            }

            Label {
                id: label14
                x: 0
                y: 61
                text: qsTr("Schlussklausel")
            }

            Label {
                id: label15
                x: 0
                y: 107
                text: qsTr("Signatur")
            }

            TextField {
                id: greetings
                x: 93
                y: 48
                width: 243
                height: 40
                text: "Mit freundlichen Grüssen"
                placeholderText: qsTr("")
            }

            TextField {
                id: signature
                x: 93
                y: 94
                width: 243
                height: 40
                placeholderText: qsTr("")
            }

            Label {
                id: label16
                x: 93
                y: 140
                text: qsTr("(default: Absendername)")
            }
        }

        GroupBox {
            id: dates
            x: 10
            width: 360
            height: 125
            anchors.top: texte.bottom
            anchors.topMargin: 5
            title: qsTr("Datum")

            RadioButton {
                id: useDateToday
                x: 0
                y: 0
                text: qsTr(" heutiges Datum")
                checked: true
            }

            RadioButton {
                id: useDateSpcified
                x: 0
                y: 41
                text: qsTr("Datum eingeben:")
            }

            TextField {
                id: dateDay
                x: 157
                y: 41
                width: 43
                height: 40
                placeholderText: qsTr("TT")
            }

            TextField {
                id: dateMonth
                x: 206
                y: 41
                width: 43
                height: 40
                placeholderText: qsTr("MM")
            }

            TextField {
                id: dateYear
                x: 255
                y: 41
                width: 69
                height: 40
                placeholderText: qsTr("JJJJ")
            }
        }

        GroupBox {
            id: texte
            x: 10
            width: 780
            height: 205
            anchors.top: grpPositions.bottom
            anchors.topMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 10
            title: qsTr("Texte")

            TextArea {
                id: textBeforePositions
                y: 20
                width: 375
                height: 140
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
            }

            TextArea {
                id: textAfterPositions
                x: 381
                y: 21
                width: 375
                height: 140
                anchors.right: parent.right
                anchors.rightMargin: 0
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
            }

            Label {
                id: label
                text: qsTr("Text vor Positionen")
                anchors.top: parent.top
                anchors.topMargin: 0
                anchors.left: parent.left
                anchors.leftMargin: 0
            }

            Label {
                id: label12
                x: 0
                y: 7
                text: qsTr("Text nach Positionen")
                anchors.topMargin: 0
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.leftMargin: 381
            }
        }

        Button {
            id: btnCreatePdf
            x: 10
            y: 1148
            text: qsTr("PDF erzeugen")
        }

        Button {
            id: btnSave
            x: 116
            y: 1148
            text: qsTr("Speichern")
        }

        Button {
            id: btnLoad
            x: 222
            y: 1148
            text: qsTr("Laden")
        }
    }
}
