import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Dialogs 1.2
import com.nina.ui 1.0



InvoiceForm {

    InvoiceModel {
        id: invoiceModel

        settings: SettingsModel {
            isPhoneInBottomField: settings.sender.phoneInBottomLine.checked
            onIsPhoneInBottomFieldChanged: { settings.sender.phoneInBottomLine.checked = isPhoneInBottomField }

            fontSize: parseInt(settings.font.fontSize.text)
            onFontSizeChanged: { settings.font.fontSize.text = fontSize }

            fontSkip: parseInt(settings.font.fontSkip.text)
            onFontSkipChanged: { settings.font.fontSkip.text = fontSkip }

            positionSkip: parseInt(settings.font.positionSkip.text)
            onPositionSkipChanged: { settings.font.positionSkip.text = positionSkip }
        }

        date: DateModel {      
            useDateToday: settings.date.useToday.checked
            onUseDateTodayChanged: {
                settings.date.useToday.checked = useDateToday
                settings.date.useSpecified.checked = !useDateToday
            }

            day: parseInt(settings.date.day.text)
            onDayChanged: { settings.date.day.text = day }

            month: parseInt(settings.date.month.text)
            onMonthChanged: { settings.date.dmonth.text = month }

            year: parseInt(settings.date.year.text)
            onYearChanged: { settings.date.year.text = year }
        }

        sender: SenderModel {
            address: AddressModel {
                name: settings.sender.name.text
                onNameChanged: { settings.sender.name.text = name }

                company: settings.sender.company.text
                onCompanyChanged: { settings.sender.company.text = company }

                street: settings.sender.street.text
                onStreetChanged: { settings.sender.street.text = street }

                zipCode: parseInt(settings.sender.zipCode.text)
                onZipCodeChanged: { settings.sender.zipCode.text = zipCode }

                place: settings.sender.place.text
                onPlaceChanged: { settings.sender.place.text = place }

                country: settings.sender.country.text
                onCountryChanged: { settings.sender.country.text = country }
            }
            bank: BankModel {
                name: settings.bank.name.text
                onNameChanged: { settings.bank.name.text = name }

                account: settings.bank.account.text
                onAccountChanged: { settings.bank.account.text = account }

                bic: settings.bank.bic.text
                onBicChanged: { settings.bank.bic.text = bic }

                iban: settings.bank.iban.text
                onIbanChanged: { settings.bank.iban.text = iban }
            }

            phone: settings.sender.phone.text
            onPhoneChanged: { settings.sender.phone.text = phone }

            mobilePhone: settings.sender.mobilePhone.text
            onMobilePhoneChanged: { settings.sender.mobilePhone.text = mobilePhone }

            email: settings.sender.email.text
            onEmailChanged: { settings.sender.email.text = email }

            webpage: settings.sender.webpage.text
            onWebpageChanged: { settings.sender.webpage.text = webpage }

            signature: settings.misc.signature.text
            onSignatureChanged: { settings.misc.signature.text = signature }

            greetings: settings.misc.greetings.text
            onGreetingsChanged: { settings.misc.greetings.text = greetings }
        }

        receiver: ReceiverModel {
            salutation: settings.receiver.salutation.text
            onSalutationChanged: { settings.receiver.salutation.text = salutation }

            address: AddressModel {
                name: settings.receiver.name.text
                onNameChanged: { settings.receiver.name.text = name }

                company: settings.receiver.company.text
                onCompanyChanged: { settings.receiver.company.text = company }

                street: settings.receiver.street.text
                onStreetChanged: { settings.receiver.street.text = street }

                zipCode: parseInt(settings.receiver.zipCode.text)
                onZipCodeChanged: { settings.receiver.zipCode.text = zipCode }

                place: settings.receiver.place.text
                onPlaceChanged: { settings.receiver.place.text = place }

                country: settings.receiver.country.text
                onCountryChanged: { settings.receiver.country.text = country }

                usePoBox: settings.receiver.usePoBox.checked
                onUsePoBoxChanged: { settings.receiver.usePoBox.checked = usePoBox }
            }
        }

        positions: PositionContainerModel {
            id: positionContainerModel
        }

        vat: VatModel {
            id: vatModel

            showVat: settings.vat.show.checked
            onShowVatChanged: { settings.vat.show.checked = showVat }

            pricesInclVat: settings.vat.pricesInclVat.checked
            onPricesInclVatChanged: {
                settings.vat.pricesInclVat.checked = pricesInclVat
                settings.vat.pricesExclVat.checked = !pricesInclVat
            }

            vatNumber: settings.vat.number.text
            onVatNumberChanged: { settings.vat.number.text = vatNumber }

            taxRate: 8.0
            onTaxRateChanged: { settings.vat.taxRate.text = taxRate }
        }

        misc: MiscModel {
            id: miscModel

            title: settings.misc.title.text
            onTitleChanged: { settings.misc.title.text = title }

            textBeforePositions: settings.texts.beforePositions.text
            onTextBeforePositionsChanged: { settings.texts.beforePositions.text = textBeforePositions }

            textAfterPositions: settings.texts.afterPositions.text
            onTextAfterPositionsChanged: { settings.texts.afterPositions.text = textAfterPositions }
        }

        onError: {
            showWarningDialog("Error", message)
        }
    }


    /// \todo Change this to onEditingFinished but shomehow the current qt verion
    /// has trouble with it.
    settings.vat.taxRate.onTextChanged: {
        var rate = parseFloat( settings.vat.taxRate.text )
        if( isNaN(rate) )
            invoiceModel.vat.taxRate = 0
        else
            invoiceModel.vat.taxRate = rate
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

    function createPdf() {
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
    function save() {
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
    function open() {
        fileOpenDialog.open()
    }


    Component.onCompleted: {
        invoiceModel.loadDefaultSettings()
    }
}
