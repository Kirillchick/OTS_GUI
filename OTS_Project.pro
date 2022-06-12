QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Analyzer.cpp \
    Angle.cpp \
    DefinedPoint.cpp \
    LogManager.cpp \
    Model.cpp \
    PaintWidget.cpp \
    Ray.cpp \
    TruePoint.cpp \
    Vector.cpp \
    Visor.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Analyzer.h \
    Angle.h \
    DefinedPoint.h \
    LogManager.h \
    LogMаnаger.h \
    LogMаnаger.h \
    LogMаnаger.h \
    Model.h \
    PaintWidget.h \
    Ray.h \
    TruePoint.h \
    Vector.h \
    Visor.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
