#include "invoicemodel.h"

// Qt includes
#include <QDesktopServices>
#include <QUrl>

// Nina includes
#include <conversion.h>



InvoiceModel::InvoiceModel()
    : m_settings( new SettingsModel() )
    , m_date( new DateModel() )
    , m_sender( new SenderModel() )
    , m_receiver( new ReceiverModel() )
    , m_positions( new PositionContainerModel() )
{
}

nina::domain::Invoice
InvoiceModel::createDomain() const
{
    nina::domain::Invoice invoice;
    invoice.setTitle( toString(m_title) );
    invoice.setSettings( m_settings->createDomain() );
    invoice.setDate( m_date->createDomain() );
    invoice.setSender( m_sender->createDomain() );
    invoice.setReceiver( m_receiver->createDomain() );
    invoice.setPositions( m_positions->createDomain() );
    invoice.setTextAfterPositions( toString(m_textAfterPositions) );
    invoice.setTextBeforePositions( toString(m_textBeforePositions) );
    return invoice;
}

QString
InvoiceModel::createPdf()
{
    std::string errormsg;
    auto pdfFile = m_pdfCreator(createDomain(), errormsg );
    if( !errormsg.empty() ) {
        return QString::fromStdString(errormsg);
    }

    // Open PDF
    QDesktopServices::openUrl( QUrl(QString("file://") + QString::fromStdString(pdfFile.native())) );
    return QString();
}
