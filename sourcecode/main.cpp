#include "mainwindow.h"
#include <QApplication>
#include "msfactory.h"
#include "managerstudentfactory.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MSfactory *mf=new ManagerStudentFactory;
    MainWindow w(0,mf);
    w.show();
    return a.exec();
}
