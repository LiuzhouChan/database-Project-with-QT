#-------------------------------------------------
#
# Project created by QtCreator 2016-11-24T22:36:03
#
#-------------------------------------------------

QT       += core gui sql  KWidgetsAddons

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sourcecode
TEMPLATE = app
INCLUDEPATH += "/usr/include/qt/QtGui"

SOURCES += main.cpp\
        mainwindow.cpp \
    adminmainwindow.cpp \
    studentmainwindow.cpp \
    manager.cpp \
    student.cpp \
    book.cpp \
    util.cpp \
    brrowrecord.cpp \
    returnrecord.cpp \
    renewrecord.cpp \
    account.cpp \
    dmodifybook.cpp \
    dnewbook.cpp \
    dnewreader.cpp \
    dfinemanager.cpp \
    dsqlip.cpp \
    dchangepassword.cpp \
    dmodifyreader.cpp \
    schangepassword.cpp

HEADERS  += mainwindow.h \
    adminmainwindow.h \
    studentmainwindow.h \
    manager.h \
    student.h \
    book.h \
    util.h \
    brrowrecord.h \
    returnrecord.h \
    renewrecord.h \
    account.h \
    dmodifybook.h \
    dnewbook.h \
    dnewreader.h \
    dfinemanager.h \
    dsqlip.h \
    dchangepassword.h \
    dmodifyreader.h \
    schangepassword.h

FORMS    += mainwindow.ui \
    adminmainwindow.ui \
    studentmainwindow.ui \
    dmodifybook.ui \
    dnewbook.ui \
    dnewreader.ui \
    dfinemanager.ui \
    dsqlip.ui \
    dchangepassword.ui \
    dmodifyreader.ui \
    schangepassword.ui
