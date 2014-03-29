# -------------------------------------------------
# Project created by QtCreator 2011-01-30T10:26:20
# -------------------------------------------------
QT += widgets
TARGET = Joypick
TEMPLATE = app
SOURCES += main.cpp \
    joypick.cpp \
    qjoystick.cpp
HEADERS += joypick.h \
    qjoystick.h
INCLUDEPATH += usr/include/SDL
LIBS += -lSDL
