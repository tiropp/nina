QT += qml quick widgets

CONFIG += c++11 qtquickcompiler


CONFIG(debug, debug|release) {
    CONFIG -= debug release
    CONFIG += debug
}
CONFIG(release, debug|release) {
    CONFIG -= debug release
    CONFIG += release
}

SOURCES += main.cpp \
    invoicemodel.cpp \
    sendermodel.cpp \
    positionmodel.cpp \
    positioncontainermodel.cpp \
    addressmodel.cpp \
    receivermodel.cpp \
    bankmodel.cpp \
    settingsmodel.cpp \
    datemodel.cpp \
    filesavedialog.cpp \
    filedialogbase.cpp \
    fileopendialog.cpp \
    vatmodel.cpp \
    detail/conversion.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

## Additional include pathes
INCLUDEPATH += $$PWD/../../domain

## Additional librarires
linux {
    debug:   LIBS += -L$$PWD/../../../_build/linux/debug/src/domain/nina
    release: LIBS += -L$$PWD/../../../_build/linux/release/src/domain/nina
    LIBS += -lnina_domain
    LIBS += -lboost_system -lboost_filesystem -lboost_serialization
}
win32 {
    debug:   LIBS += -L$$PWD/../../../_build/windows_shared/debug/src/domain/nina
    release: LIBS += -L$$PWD/../../../_build/windows_shared/release/src/domain/nina
    LIBS += -lnina_domain
    LIBS += -lboost_system-mt -lboost_filesystem-mt -lboost_serialization-mt
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
    settingsmodel.h \
    datemodel.h \
    filesavedialog.h \
    filedialogbase.h \
    fileopendialog.h \
    vatmodel.h \
    detail/macros.h \
    detail/conversion.h

FORMS +=

DISTFILES +=
