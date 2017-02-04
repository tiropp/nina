// Qt includes
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

// Nina includes
#include <settingsmodel.h>
#include <datemodel.h>
#include <addressmodel.h>
#include <bankmodel.h>
#include <sendermodel.h>
#include <receivermodel.h>
#include <positionmodel.h>
#include <positioncontainermodel.h>
#include <vatmodel.h>
#include <invoicemodel.h>
#include <filesavedialog.h>
#include <fileopendialog.h>



int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
    app.setApplicationName("nina");
    app.setOrganizationName("tiropp");

    QQmlApplicationEngine engine;
    qmlRegisterType<SettingsModel>("com.nina.ui", 1, 0, "SettingsModel");
    qmlRegisterType<DateModel>("com.nina.ui", 1, 0, "DateModel");
    qmlRegisterType<AddressModel>("com.nina.ui", 1, 0, "AddressModel");
    qmlRegisterType<BankModel>("com.nina.ui", 1, 0, "BankModel");
    qmlRegisterType<SenderModel>("com.nina.ui", 1, 0, "SenderModel");
    qmlRegisterType<ReceiverModel>("com.nina.ui", 1, 0, "ReceiverModel");
    qmlRegisterType<PositionModel>("com.nina.ui", 1, 0, "PositionModel");
    qmlRegisterType<PositionContainerModel>("com.nina.ui", 1, 0, "PositionContainerModel");
    qmlRegisterType<VatModel>("com.nina.ui", 1, 0, "VatModel");
    qmlRegisterType<InvoiceModel>("com.nina.ui", 1, 0, "InvoiceModel");
    qmlRegisterType<FileSaveDialog>("com.nina.ui", 1, 0, "FileSaveDialog");
    qmlRegisterType<FileOpenDialog>("com.nina.ui", 1, 0, "FileOpenDialog");
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    //InvoiceModel invoice;
    //engine.rootContext()->setContextProperty("invoice", &invoice);


    return app.exec();
}
