# -------------------------------------------------
# Project created by QtCreator 2010-01-15T23:46:34
# -------------------------------------------------
TARGET = QLedIndicatorPlugin
TEMPLATE = lib
QT += widgets designer
CONFIG += qt plugin \
    release \
    dll
DEFINES += QLEDINDICATORPLUGIN_LIBRARY
SOURCES += qledindicatorplugin.cpp \
    ../qledindicator.cpp
HEADERS += qledindicatorplugin.h \
    QLedIndicatorPlugin_global.h \
    ../qledindicator.h
OTHER_FILES += qledindicator.json
target.path = /opt/Qt/5.1.1/gcc/plugins/designer
INSTALLS += target
