#include "sqlip.h"
#include "ui_sqlip.h"

sqlip::sqlip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sqlip),server_ip("127.0.0.1"),user_name("root"),pass_wd("xiaoliuliu"),
    database_name("sqlproject")
{
    ui->setupUi(this);
    ui->serverip->setText(server_ip);
    ui->sqlusername->setText(user_name);
    ui->sqlpassword->setText(pass_wd);
    ui->databasename->setText(database_name);

}


sqlip::~sqlip()
{

    if(QSqlDatabase::contains("myconnection"))
    {
       QSqlDatabase db=QSqlDatabase::database("myconnection");
       db.close();
    }
    delete ui;
}



void sqlip::on_pushButton_2_clicked()
{
    this->hide();
}

void sqlip::on_pushButton_clicked()
{
    server_ip=QString(ui->serverip->text());
    user_name=QString(ui->sqlusername->text());
    pass_wd=QString(ui->sqlpassword->text());
    database_name=QString(ui->databasename->text());

    QSqlDatabase db;
    if(QSqlDatabase::contains("myconnection"))
    {
       db=QSqlDatabase::database("myconnection");
    }else{
       db=QSqlDatabase::addDatabase("QMYSQL","myconnection");
    }
    db.setHostName(server_ip);
    db.setDatabaseName(database_name);
    db.setUserName(user_name);
    db.setPassword(pass_wd);
    if(db.open())
    {
        QMessageBox::about(this,QString("messages"),"Connect to the database successfully");
        this->hide();
    }
    else
    {
        QMessageBox::warning(this,QString("messages"),"Cannot connect to the database");
    }
}
