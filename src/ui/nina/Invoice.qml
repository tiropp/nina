import QtQuick 2.5
import QtQuick.Dialogs 1.2
import com.nina.ui 1.0


InvoiceForm {
     Dialog {
        id: addPositionDialog
        title: qsTr("Neue Position")

        contentItem: Position {
            id: addPosition
            implicitWidth: childrenRect.width
            implicitHeight: childrenRect.height

            btnOK.onClicked: {         
                positionContainerModel.append(addPosition.standard.description.text,
                                              addPosition.standard.unit.text,
                                              addPosition.standard.numUnits.text,
                                              addPosition.standard.pricePerUnit.text)
                addPositionDialog.click(StandardButton.Ok)
            }
            btnCancel.onClicked: {
                addPositionDialog.click(StandardButton.Cancel)
            }
        }

        function reset() {
            addPosition.reset()
        }
    }

    Dialog {
        id: modifyPositionDialog
        title: qsTr("Position ändern")

        contentItem: Position {
            id: modifyPosition
            implicitWidth: childrenRect.width
            implicitHeight: childrenRect.height

            btnOK.onClicked: {
                positionContainerModel.setRow(
                    rowIndex.text,
                    modifyPosition.standard.description.text,
                    modifyPosition.standard.unit.text,
                    modifyPosition.standard.numUnits.text,
                    modifyPosition.standard.pricePerUnit.text
                )
                modifyPositionDialog.click(StandardButton.Ok)
            }
            btnCancel.onClicked: {
                modifyPositionDialog.click(StandardButton.Cancel)
            }

        }

        Text {
            // Dirty way to store the row index from the set() function s.t. it can be used
            // from the onClicked function.
            id: rowIndex
        }

        function set(row) {
            rowIndex.text = row
            var pos = positionContainerModel.getRow( row )
            modifyPosition.standard.description.text  = pos.description
            modifyPosition.standard.unit.text         = pos.unit
            modifyPosition.standard.numUnits.text     = pos.numUnits
            modifyPosition.standard.pricePerUnit.text = pos.pricePerUnit
        }
    }

    InvoiceModel {
        id: invoiceModel

        title: invoiceForm.title.text
        onTitleChanged: { invoiceForm.title.text = title }

        settings: SettingsModel {
            isPhoneInBottomField: senderPhoneInBottomLine.checked
            onIsPhoneInBottomFieldChanged: { invoiceForm.senderPhoneInBottomLine.checked = isPhoneInBottomField }

            fontSize: parseInt(invoiceForm.fontSize.text)
            onFontSizeChanged: { invoiceForm.fontSize.text = fontSize }

            fontSkip: parseInt(invoiceForm.fontSkip.text)
            onFontSkipChanged: { invoiceForm.fontSkip.text = fontSkip }

            positionSkip: parseInt(invoiceForm.positionSkip.text)
            onPositionSkipChanged: { invoiceForm.positionSkip.text = positionSkip }
        }

        date: DateModel {      
            useDateToday: invoiceForm.useDateToday.checked
            onUseDateTodayChanged: {
                invoiceForm.useDateToday.checked = useDateToday
                invoiceForm.useDateSpcified.checked = !useDateToday
            }

            day: parseInt(dateDay.text)
            onDayChanged: { dateDay.text = day }

            month: parseInt(dateMonth.text)
            onMonthChanged: { dateMonth.text = month }

            year: parseInt(dateYear.text)
            onYearChanged: { dateYear.text = year }
        }

        sender: SenderModel {
            address: AddressModel {
                name: senderName.text
                onNameChanged: { senderName.text = name }

                company: senderCompany.text
                onCompanyChanged: { senderCompany.text = company }

                street: senderStreet.text
                onStreetChanged: { senderStreet.text = street }

                zipCode: parseInt(senderZipCode.text)
                onZipCodeChanged: { senderZipCode.text = zipCode }

                place: senderPlace.text
                onPlaceChanged: { senderPlace.text = place }

                country: senderCountry.text
                onCountryChanged: { senderCountry.text = country }
            }
            bank: BankModel {
                name: bankName.text
                onNameChanged: { bankName.text = name }

                bic: bankBic.text
                onBicChanged: { bankBic.text = bic }

                account: bankAccount.text
                onAccountChanged: { bankAccount.text = account }
            }

            phone: senderPhone.text
            onPhoneChanged: { senderPhone.text = phone }

            mobilePhone: senderMobilePhone.text
            onMobilePhoneChanged: { senderMobilePhone.text = mobilePhone }

            signature: invoiceForm.signature.text
            onSignatureChanged: { invoiceForm.signature.text = signature }

            greetings: invoiceForm.greetings.text
            onGreetingsChanged: { invoiceForm.greetings.text = greetings }
        }

        receiver: ReceiverModel {
            address: AddressModel {
                salutation: recvSalutation.text
                onSalutationChanged: { recvSalutation.text = salutation }

                name: recvName.text
                onNameChanged: { recvName.text = name }

                company: recvCompany.text
                onCompanyChanged: { recvCompany.text = company }

                street: recvStreet.text
                onStreetChanged: { recvStreet.text = street }

                zipCode: parseInt(recvZipCode.text)
                onZipCodeChanged: { recvZipCode.text = zipCode }

                place: recvPlace.text
                onPlaceChanged: { recvPlace.text = place }

                country: recvCountry.text
                onCountryChanged: { recvCountry.text = country }

                usePoBox: recvUsePoBox.checked
                onUsePoBoxChanged: { recvUsePoBox.checked = usePoBox }
            }
        }

        positions: PositionContainerModel {
            id: positionContainerModel
        }

        textBeforePositions: invoiceForm.textBeforePositions.text
        onTextBeforePositionsChanged: { invoiceForm.textBeforePositions.text = textBeforePositions }

        textAfterPositions: invoiceForm.textAfterPositions.text
        onTextAfterPositionsChanged: { invoiceForm.textAfterPositions.text = textAfterPositions }
    }

    btnNewPos.onClicked: {
        addPositionDialog.reset()
        addPositionDialog.open()
    }

    btnModifyPos.onClicked: {
        modifyPositionDialog.set( positions.__currentRow )
        modifyPositionDialog.open()
    }
    positions.onDoubleClicked: {
        modifyPositionDialog.set( positions.__currentRow )
        modifyPositionDialog.open()
    }

    btnDeletePos.onClicked: {
        positionContainerModel.removeRow( positions.__currentRow )
    }

    MessageDialog {
        id: warningDialog
        icon: StandardIcon.Warning
    }
    function showWarningDialog(title, msg) {
        warningDialog.title = title
        warningDialog.text = msg
        warningDialog.open()
    }

    btnCreatePdf.onClicked: {
        var errMsg = invoiceModel.createPdf();
        if( errMsg )
            showWarningDialog("PDF creation", errMsg);
    }

    FileSaveDialog {
        id: fileSaveDialog
        title: qsTr("Speichern als")
        nameFilters: ["nina files (*.nina)", "All files (*)"]
        onAccepted: {
            invoiceModel.save( fileUrl )
        }
    }
    btnSave.onClicked: {
        fileSaveDialog.open()
    }

    FileOpenDialog {
        id: fileOpenDialog
        title: qsTr("Datei öffnen")
        nameFilters: ["nina files (*.nina)", "All files (*)"]
        onAccepted: {
            invoiceModel.load( fileUrl )
        }
    }
    btnLoad.onClicked: {
        fileOpenDialog.open()
    }
}
