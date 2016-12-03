#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>

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

void MainWindow::on_loginButton_clicked()
{
    int login=0;
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select Mon,password from Manager");
    while(query.next())
    {
        QString name = query.value(0).toString();
        QString password = query.value(1).toString();
        if(name==ui->lineEdit_2->text() && password==ui->lineEdit_3->text())
        {
            login=1;
            this->hide();
            adminMainWindow *admin = new adminMainWindow(this);
            admin->show();
            return;
        }
    }

    query.exec("select Rno,password from Reader");
    while(query.next())
    {
        QString name = query.value(0).toString();
        QString password = query.value(1).toString();
        if(name==ui->lineEdit_2->text() && password==ui->lineEdit_3->text())
        {
            login=1;
            this->hide();
            studentMainWindow *student=new studentMainWindow(this);
            student->show();
            return;
        }
    }
    if(login==0)
    {
        ui->statusBar->showMessage("Either the username or password is uncorrect",5000);
    }
}
