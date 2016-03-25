#-------------------------------------------------
#
# Project created by QtCreator 2016-03-23T12:30:01
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PrimitiveGenerator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    primintivedrawingwidget.cpp \
    primitive.cpp \
    Primitives/square.cpp \
    mainwidget.cpp \
    Primitives/cube.cpp

HEADERS  += mainwindow.h \
    primintivedrawingwidget.h \
    primitive.h \
    Primitives/square.h \
    mainwidget.h \
    Primitives/cube.h

FORMS    += mainwindow.ui

RESOURCES += \
    main.qrc

DISTFILES +=
