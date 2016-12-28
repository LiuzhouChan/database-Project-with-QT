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
    schangepassword.cpp \
    booktype.cpp \
    mathbook.cpp \
    environmentbook.cpp \
    computerbook.cpp \
    financebook.cpp \
    physicsbook.cpp \
    bookfactory.cpp \
    managerstudentfactory.cpp \
    svipstudent.cpp \
    vipstudent.cpp \
    reader.cpp \
    managerfactory.cpp \
    studentfactory.cpp \
    readerfactory.cpp

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
    schangepassword.h \
    booktype.h \
    mathbook.h \
    environmentbook.h \
    computerbook.h \
    financebook.h \
    physicsbook.h \
    bookfactory.h \
    managerstudentfactory.h \
    svipstudent.h \
    vipstudent.h \
    reader.h \
    managerfactory.h \
    studentfactory.h \
    readerfactory.h

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

RESOURCES += \
    icon.qrc
