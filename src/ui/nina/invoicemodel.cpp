#include "invoicemodel.h"

// Qt includes
#include <QDesktopServices>
#include <QUrl>

// Nina domain includes
#include <nina/Archiver.h>
#include <nina/DefaultSettings.h>
#include <nina/Exception.h>

// Nina includes
#include <detail/macros.h>
#include <detail/conversion.h>



InvoiceModel::InvoiceModel()
    : m_settings( new SettingsModel() )
    , m_date( new DateModel() )
    , m_sender( new SenderModel() )
    , m_receiver( new ReceiverModel() )
    , m_positions( new PositionContainerModel() )
    , m_vat( new VatModel() )
    , m_misc( new MiscModel() )
{
}

nina::domain::Invoice
InvoiceModel::createDomain() const
{
    nina::domain::Invoice invoice;
    invoice.setSettings( m_settings->createDomain() );
    invoice.setDate( m_date->createDomain() );
    invoice.setSender( m_sender->createDomain() );
    invoice.setReceiver( m_receiver->createDomain() );
    invoice.setPositions( m_positions->createDomain() );
    invoice.setVat( m_vat->createDomain() );
    invoice.setMisc( m_misc->createDomain() );
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
    QDesktopServices::openUrl( QUrl::fromLocalFile( QString::fromStdString(pdfFile.string()) ) );
    return QString();
}

void
InvoiceModel::save(const QString& filename)
{
    try {
        nina::domain::Archiver::save(createDomain(), toString(filename));
    }
    catch( std::exception& e ) {
        emit error( tr("Schreiben der Datei '") + filename + tr("' fehlgeschlagen: ") + e.what() );
    }
}

void
InvoiceModel::load(const QString& filename)
{
    try {
        nina::domain::Invoice invoice = nina::domain::Archiver::load( toString(filename) );
        set( invoice );
    }
    catch( std::exception& e ) {
        emit error( tr("Lesen der Datei '") + filename + tr("' fehlgeschlagen: ") + e.what() );
    }
}

void
InvoiceModel::saveDefaultSettings()
{
    nina::domain::Invoice invoice = createDomain();
    nina::domain::DefaultSettings ds(invoice.getSettings(),
                                     invoice.getSender(),
                                     invoice.getVat(),
                                     invoice.getMisc());
    nina::domain::Archiver::saveDefaultSettings( ds );
}

void
InvoiceModel::loadDefaultSettings()
{
    try {
        nina::domain::DefaultSettings ds = nina::domain::Archiver::loadDefaultSettings();
        m_settings->set( ds.getSettings() );
        m_sender  ->set( ds.getSender() );
        m_vat     ->set( ds.getVat() );
        m_misc    ->set( ds.getMisc() );
    }
    catch(nina::domain::Exception& e) {
        emit error( e.what() );
    }
}

void
InvoiceModel::set(const nina::domain::Invoice& invoice)
{
    m_settings ->set( invoice.getSettings()  );
    m_date     ->set( invoice.getDate()      );
    m_sender   ->set( invoice.getSender()    );
    m_receiver ->set( invoice.getReceiver()  );
    m_positions->set( invoice.getPositions() );
    m_vat      ->set( invoice.getVat()       );
    m_misc     ->set( invoice.getMisc()      );
}

NINA_SETPROPERTY(InvoiceModel, setSettings,  SettingsModel*,          settings)
NINA_SETPROPERTY(InvoiceModel, setDate,      DateModel*,              date)
NINA_SETPROPERTY(InvoiceModel, setSender,    SenderModel*,            sender)
NINA_SETPROPERTY(InvoiceModel, setReceiver,  ReceiverModel*,          receiver)
NINA_SETPROPERTY(InvoiceModel, setPositions, PositionContainerModel*, positions)
NINA_SETPROPERTY(InvoiceModel, setVat,       VatModel*,               vat)
NINA_SETPROPERTY(InvoiceModel, setMisc,      MiscModel*,              misc)

