#-------------------------------------------------
#
# Project created by QtCreator 2016-11-24T22:36:03
#
#-------------------------------------------------

QT       += core gui sql  KWidgetsAddons

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sourcecode
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sqlip.cpp \
    adminmainwindow.cpp \
    studentmainwindow.cpp \
    editbook.cpp \
    editreader.cpp \
    bookdetail.cpp \
    manager.cpp \
    student.cpp \
    book.cpp \
    util.cpp \
    finemanager.cpp \
    changepassword.cpp

HEADERS  += mainwindow.h \
    sqlip.h \
    adminmainwindow.h \
    studentmainwindow.h \
    editbook.h \
    editreader.h \
    bookdetail.h \
    manager.h \
    student.h \
    book.h \
    util.h \
    finemanager.h \
    changepassword.h

FORMS    += mainwindow.ui \
    sqlip.ui \
    adminmainwindow.ui \
    studentmainwindow.ui \
    editbook.ui \
    editreader.ui \
    bookdetail.ui \
    finemanager.ui \
    changepassword.ui
