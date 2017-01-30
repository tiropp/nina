// Qt includes
#include <QGuiApplication>
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
#include <invoicemodel.h>



int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<SettingsModel>("com.nina.ui", 1, 0, "SettingsModel");
    qmlRegisterType<DateModel>("com.nina.ui", 1, 0, "DateModel");
    qmlRegisterType<AddressModel>("com.nina.ui", 1, 0, "AddressModel");
    qmlRegisterType<BankModel>("com.nina.ui", 1, 0, "BankModel");
    qmlRegisterType<SenderModel>("com.nina.ui", 1, 0, "SenderModel");
    qmlRegisterType<ReceiverModel>("com.nina.ui", 1, 0, "ReceiverModel");
    qmlRegisterType<PositionModel>("com.nina.ui", 1, 0, "PositionModel");
    qmlRegisterType<PositionContainerModel>("com.nina.ui", 1, 0, "PositionContainerModel");
    qmlRegisterType<InvoiceModel>("com.nina.ui", 1, 0, "InvoiceModel");
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    //InvoiceModel invoice;
    //engine.rootContext()->setContextProperty("invoice", &invoice);


    return app.exec();
}
