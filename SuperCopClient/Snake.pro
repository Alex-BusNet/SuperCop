#-------------------------------------------------
#
# Project created by QtCreator 2017-02-25T14:08:16
#
#-------------------------------------------------

QT       += core gui quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Snake
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    renderobject.cpp \
    joingame.cpp

HEADERS  += mainwindow.h \
    renderobject.h \
    joingame.h

FORMS    += mainwindow.ui \
    joingame.ui
