#ifndef INVOICEMODEL_H
#define INVOICEMODEL_H

// Qt includes
#include <QObject>
#include <QPointer>

// Nina domain includes
#include <nina/Invoice.h>


// Nina domain includes
#include <nina/PdfCreator.h>

// Nina includes
#include <settingsmodel.h>
#include <datemodel.h>
#include <sendermodel.h>
#include <receivermodel.h>
#include <positioncontainermodel.h>



class InvoiceModel: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(SettingsModel* settings READ settings WRITE setSettings NOTIFY settingsChanged)
    Q_PROPERTY(DateModel* date READ date WRITE setDate NOTIFY dateChanged)
    Q_PROPERTY(SenderModel* sender READ sender WRITE setSender NOTIFY senderChanged)
    Q_PROPERTY(ReceiverModel* receiver READ receiver WRITE setReceiver NOTIFY receiverChanged)
    Q_PROPERTY(PositionContainerModel* positions READ positions WRITE setPositions NOTIFY positionsChanged)
    Q_PROPERTY(QString textBeforePositions READ textBeforePositions WRITE setTextBeforePositions NOTIFY textBeforePositionsChanged)
    Q_PROPERTY(QString textAfterPositions READ textAfterPositions WRITE setTextAfterPositions NOTIFY textAfterPositionsChanged)

  public:
    InvoiceModel();

  public:
    nina::domain::Invoice createDomain() const;

    /// \brief Create PDF file
    /// \return In case of an error a non-empty string is returned
    Q_INVOKABLE QString createPdf();

  public:
    QString title() const { return m_title; }
    SettingsModel* settings() const { return m_settings; }
    DateModel* date() const { return m_date; }
    SenderModel* sender() const { return m_sender; }
    ReceiverModel* receiver() const { return m_receiver; }
    PositionContainerModel* positions() const { return m_positions; }
    QString textBeforePositions() const { return m_textBeforePositions; }
    QString textAfterPositions() const { return m_textAfterPositions; }

  public:
    void setTitle(const QString& title) { m_title = title; }
    void setSettings(SettingsModel* settings) { m_settings = settings; }
    void setDate(DateModel* date) { m_date = date; }
    void setSender(SenderModel* sender) { m_sender = sender; }
    void setReceiver(ReceiverModel* receiver) { m_receiver = receiver; }
    void setPositions(PositionContainerModel* positions) { m_positions = positions; }
    void setTextBeforePositions(const QString& text) { m_textBeforePositions = text; }
    void setTextAfterPositions(const QString& text) { m_textAfterPositions = text; }

  signals:
    void titleChanged();
    void settingsChanged();
    void dateChanged();
    void senderChanged();
    void receiverChanged();
    void positionsChanged();
    void textBeforePositionsChanged();
    void textAfterPositionsChanged();

  private:
    QString m_title;
    QPointer<SettingsModel> m_settings;
    QPointer<DateModel> m_date;
    QPointer<SenderModel> m_sender;
    QPointer<ReceiverModel> m_receiver;
    QPointer<PositionContainerModel> m_positions;
    QString m_textBeforePositions;
    QString m_textAfterPositions;
    nina::domain::PdfCreator m_pdfCreator;
};

#endif // INVOICEMODEL_H
