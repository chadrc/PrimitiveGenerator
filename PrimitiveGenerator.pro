#-------------------------------------------------
#
# Project created by QtCreator 2016-03-23T12:30:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PrimitiveGenerator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    primintivedrawingwidget.cpp \
    primitive.cpp

HEADERS  += mainwindow.h \
    primintivedrawingwidget.h \
    primitive.h

FORMS    += mainwindow.ui
