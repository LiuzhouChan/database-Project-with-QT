#include "studentmainwindow.h"
#include "ui_studentmainwindow.h"

studentMainWindow::studentMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::studentMainWindow)
{
    ui->setupUi(this);
}

studentMainWindow::~studentMainWindow()
{
    delete ui;
}
