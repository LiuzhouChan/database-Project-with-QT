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
    ui->lineEdit_2->setText("20160000");
    ui->lineEdit_3->setText("1234");
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
            manager * man=new manager(new QString(name),new QString(password));
            adminMainWindow *admin = new adminMainWindow(this,man);
            admin->show();
            return;
        }
    }

    query.exec("select * from Reader");
    while(query.next())
    {
        QString name = query.value(0).toString();
        QString password = query.value(1).toString();
        if(name==ui->lineEdit_2->text() && password==ui->lineEdit_3->text())
        {
            login=1;
            this->hide();
            student *stu=new student(new QString(query.value(0).toString()),new QString(query.value(1).toString())
                                     ,new QString(query.value(2).toString())
                                    ,new QString(query.value(3).toString()),new QString(query.value(4).toString()),
                                     new QString(query.value(5).toString())
                                    ,query.value(6).toInt(),query.value(7).toDouble());
            studentMainWindow *studen=new studentMainWindow(this,stu);
            studen->show();
            return;
        }
    }
    if(login==0)
    {
        ui->statusBar->showMessage("Either the username or password is uncorrect",5000);
    }
}
