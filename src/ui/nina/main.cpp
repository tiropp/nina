// STL includes
#include <iostream>

// Qt includes
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

// Boost includes
#include <boost/stacktrace.hpp>
#include <boost/exception/all.hpp>
#include <boost/stacktrace/stacktrace_fwd.hpp>

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
#include <miscmodel.h>
#include <invoicemodel.h>
#include <filesavedialog.h>
#include <fileopendialog.h>


int
run(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::addLibraryPath("./");
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
    qmlRegisterType<MiscModel>("com.nina.ui", 1, 0, "MiscModel");
    qmlRegisterType<InvoiceModel>("com.nina.ui", 1, 0, "InvoiceModel");
    qmlRegisterType<FileSaveDialog>("com.nina.ui", 1, 0, "FileSaveDialog");
    qmlRegisterType<FileOpenDialog>("com.nina.ui", 1, 0, "FileOpenDialog");
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));


    return app.exec();
}

int
main(int argc, char *argv[])
{
    using traced = boost::error_info<struct tag_stacktrace, boost::stacktrace::stacktrace>;

    try {
        return run(argc, argv);
    } catch(const std::exception& e) {
        std::cerr << "Uncaught exception " << typeid(e).name() << ": " << e.what() << "\n";

        const auto* trace = boost::get_error_info<traced>(e);
        if(trace) {
            std::cerr << "Stack backtrace:\n" << *trace << "\n";
        } else {
            std::cerr << "Stack backtrace:\n" << boost::stacktrace::stacktrace() << "\n";
        }
    } catch(...) {
        std::cerr << "Stack backtrace:\n" << boost::stacktrace::stacktrace() << "\n";
    }
}
