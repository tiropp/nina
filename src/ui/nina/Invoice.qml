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
        settings: SettingsModel {
            isPhoneInBottomField: senderPhoneInBottomLine.checked
            fontSize: parseInt(invoiceForm.fontSize.text)
            fontSkip: parseInt(invoiceForm.fontSkip.text)
            positionSkip: parseInt(invoiceForm.positionSkip.text)
        }
        date: DateModel {      
            useDateToday: invoiceForm.useDateToday.checked
            useDateSpecified: invoiceForm.useDateSpcified.checked
            day: parseInt(dateDay.text)
            month: parseInt(dateMonth.text)
            year: parseInt(dateYear.text)
        }
        sender: SenderModel {
            address: AddressModel {
                name: senderName.text
                company: senderCompany.text
                street: senderStreet.text
                zipCode: parseInt(senderZipCode.text)
                place: senderPlace.text
                country: senderCountry.text
            }
            bank: BankModel {
                name: bankName.text
                bic: bankBic.text
                account: bankAccount.text
            }
            phone: senderPhone.text
            mobilePhone: senderMobilePhone.text
            signature: invoiceForm.signature.text
            greetings: invoiceForm.greetings.text
        }
        receiver: ReceiverModel {
            address: AddressModel {
                salutation: recvSalutation.text
                name: recvName.text
                company: recvCompany.text
                street: recvStreet.text
                zipCode: parseInt(recvZipCode.text)
                place: recvPlace.text
                country: recvCountry.text
                usePoBox: recvUsePoBox.checked
            }
        }
        positions: PositionContainerModel {
            id: positionContainerModel
        }
        textBeforePositions: invoiceForm.textBeforePositions.text
        textAfterPositions:  invoiceForm.textAfterPositions.text
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

    createPdf.onClicked: {
        var errMsg = invoiceModel.createPdf();
        if( errMsg )
            showWarningDialog("PDF creation", errMsg);
    }
}
