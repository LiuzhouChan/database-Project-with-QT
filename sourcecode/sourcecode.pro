#-------------------------------------------------
#
# Project created by QtCreator 2016-11-24T22:36:03
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sourcecode
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sqlip.cpp

HEADERS  += mainwindow.h \
    sqlip.h

FORMS    += mainwindow.ui \
    sqlip.ui
