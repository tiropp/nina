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
#include <vatmodel.h>



class InvoiceModel: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(SettingsModel* settings READ settings WRITE setSettings NOTIFY settingsChanged)
    Q_PROPERTY(DateModel* date READ date WRITE setDate NOTIFY dateChanged)
    Q_PROPERTY(SenderModel* sender READ sender WRITE setSender NOTIFY senderChanged)
    Q_PROPERTY(ReceiverModel* receiver READ receiver WRITE setReceiver NOTIFY receiverChanged)
    Q_PROPERTY(PositionContainerModel* positions READ positions WRITE setPositions NOTIFY positionsChanged)
    Q_PROPERTY(VatModel* vat READ vat WRITE setVat NOTIFY vatChanged)
    Q_PROPERTY(QString textBeforePositions READ textBeforePositions WRITE setTextBeforePositions NOTIFY textBeforePositionsChanged)
    Q_PROPERTY(QString textAfterPositions READ textAfterPositions WRITE setTextAfterPositions NOTIFY textAfterPositionsChanged)


  public:
    InvoiceModel();

  public:
    nina::domain::Invoice createDomain() const;

    /// \brief Create PDF file
    /// \return In case of an error a non-empty string is returned
    Q_INVOKABLE QString createPdf();

    /// \brief Store information to file
    Q_INVOKABLE void save(const QString& filename);

    /// \brief Load information from file
    Q_INVOKABLE void load(const QString& filename);

  public:
    QString title() const { return m_title; }
    SettingsModel* settings() const { return m_settings; }
    DateModel* date() const { return m_date; }
    SenderModel* sender() const { return m_sender; }
    ReceiverModel* receiver() const { return m_receiver; }
    PositionContainerModel* positions() const { return m_positions; }
    VatModel* vat() const { return m_vat; }
    QString textBeforePositions() const { return m_textBeforePositions; }
    QString textAfterPositions() const { return m_textAfterPositions; }

  public:
    void set(const nina::domain::Invoice& invoice);
    void setTitle(const QString& title);
    void setSettings(SettingsModel* settings);
    void setDate(DateModel* date);
    void setSender(SenderModel* sender);
    void setReceiver(ReceiverModel* receiver);
    void setPositions(PositionContainerModel* positions);
    void setVat(VatModel* vat);
    void setTextBeforePositions(const QString& text);
    void setTextAfterPositions(const QString& text);

  signals:
    void titleChanged();
    void settingsChanged();
    void dateChanged();
    void senderChanged();
    void receiverChanged();
    void positionsChanged();
    void vatChanged();
    void textBeforePositionsChanged();
    void textAfterPositionsChanged();

  private:
    QString m_title;
    QPointer<SettingsModel> m_settings;
    QPointer<DateModel> m_date;
    QPointer<SenderModel> m_sender;
    QPointer<ReceiverModel> m_receiver;
    QPointer<PositionContainerModel> m_positions;
    QPointer<VatModel> m_vat;
    QString m_textBeforePositions;
    QString m_textAfterPositions;
    nina::domain::PdfCreator m_pdfCreator;
};

#endif // INVOICEMODEL_H
