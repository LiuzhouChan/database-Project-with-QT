#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ip=new sqlip(this);
}

MainWindow::~MainWindow()
{
    delete ip;
    delete ui;
}

void MainWindow::on_actionSQL_server_IP_triggered()
{

    ip->show();
}

void MainWindow::on_actionAbout_QT_triggered()
{
    QMessageBox::aboutQt(this,"About QT");
}
