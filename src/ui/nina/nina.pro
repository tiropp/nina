QT += qml quick

CONFIG += c++11

SOURCES += main.cpp \
    invoicemodel.cpp \
    sendermodel.cpp \
    positionmodel.cpp \
    positioncontainermodel.cpp \
    addressmodel.cpp \
    receivermodel.cpp \
    bankmodel.cpp \
    conversion.cpp \
    settingsmodel.cpp \
    datemodel.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

## Additional include pathes
INCLUDEPATH += $$PWD/../../domain

## Additional librarires
linux {
    CONFIG(debug):   LIBS += -L$$PWD/../../domain/_build/linux/debug/nina
    CONFIG(release): LIBS += -L$$PWD/../../domain/_build/linux/release/nina
    LIBS += -lnina_domain
    LIBS += -lboost_system -lboost_filesystem
}
win32 {
    CONFIG(debug):   LIBS += -L$$PWD/../../domain/_build/windows/debug/nina
    CONFIG(release): LIBS += -L$$PWD/../../domain/_build/windows/release/nina
    LIBS += -lnina_domain
    LIBS += -lboost_system-mt -lboost_filesystem-mt
}

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    invoicemodel.h \
    sendermodel.h \
    positionmodel.h \
    positioncontainermodel.h \
    addressmodel.h \
    receivermodel.h \
    bankmodel.h \
    conversion.h \
    settingsmodel.h \
    datemodel.h

FORMS +=

DISTFILES +=
