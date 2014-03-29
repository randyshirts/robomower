#-------------------------------------------------
#
# Project created by QtCreator 2013-12-07T13:27:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RoboMowerGUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    console.cpp \
    settingsdialog.cpp \
    robotgui.cpp \
    qledindicator.cpp

HEADERS  += mainwindow.h \
    console.h \
    settingsdialog.h \
    robotgui.h \
    heartbeattimer.h \
    qledindicator.h

FORMS    += mainwindow.ui \
    settingsdialog.ui \
    robotgui.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../opt/Qt/5.1.1/gcc/lib/release/ -lQt5SerialPort
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../opt/Qt/5.1.1/gcc/lib/debug/ -lQt5SerialPort
else:unix: LIBS += -L$$PWD/../../../../../../opt/Qt/5.1.1/gcc/lib/ -lQt5SerialPort

RESOURCES += \
    terminal.qrc \
    terminal.qrc

INCLUDEPATH += $$PWD/../../../../../../opt/Qt/5.1.1/gcc/include
DEPENDPATH += $$PWD/../../../../../../opt/Qt/5.1.1/gcc/include
LIBS += -L/opt/Qt/plugins/designer


