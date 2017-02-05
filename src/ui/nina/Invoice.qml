import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Dialogs 1.2
import com.nina.ui 1.0



InvoiceForm {

    AddPositionDialog {
        id: addPositionDialog
    }
    ModifyPositionDialog {
        id: modifyPositionDialog
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

                account: bankAccount.text
                onAccountChanged: { bankAccount.text = account }

                bic: bankBic.text
                onBicChanged: { bankBic.text = bic }

                iban: bankIban.text
                onIbanChanged: { bankIban.text = iban }
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
            salutation: recvSalutation.text
            onSalutationChanged: { recvSalutation.text = salutation }

            address: AddressModel {
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

        vat: VatModel {
            id: vatModel

            showVat: invoiceForm.showVat.checked
            onShowVatChanged: { invoiceForm.showVat.checked = showVat }

            pricesInclVat: invoiceForm.pricesInclVat.checked
            onPricesInclVatChanged: {
                invoiceForm.pricesInclVat.checked = pricesInclVat
                invoiceForm.pricesExclVat.checked = !pricesInclVat
            }

            vatNumber: invoiceForm.vatNumber.text
            onVatNumberChanged: { invoiceForm.vatNumber.text = vatNumber }

            taxRate: 8.0
            onTaxRateChanged: { invoiceForm.vatTaxRate.text = taxRate }
        }

        textBeforePositions: invoiceForm.textBeforePositions.text
        onTextBeforePositionsChanged: { invoiceForm.textBeforePositions.text = textBeforePositions }

        textAfterPositions: invoiceForm.textAfterPositions.text
        onTextAfterPositionsChanged: { invoiceForm.textAfterPositions.text = textAfterPositions }
    }

    /// \todo Change this to onEditingFinished but shomehow the current qt verion
    /// has trouble with it.
    vatTaxRate.onTextChanged: {
        var rate = parseFloat( vatTaxRate.text )
        if( isNaN(rate) )
            invoiceModel.vat.taxRate = 0
        else
            invoiceModel.vat.taxRate = rate
    }

    btnNewPos.onClicked: {
        addPositionDialog.open()
    }

    btnModifyPos.onClicked: {
        modifyPositionDialog.open( positions.getCurrentRow() )
    }

    btnDeletePos.onClicked: {
        positionContainerModel.removeRow( positions.getCurrentRow() )
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
