#include "dsqlip.h"
#include "ui_dsqlip.h"

dsqlip::dsqlip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dsqlip),server_ip("127.0.0.1"),user_name("root"),pass_wd("xiaoliuliu"),
    database_name("sqlproject")
{
    ui->setupUi(this);
    ui->serverip->setText(server_ip);
    ui->sqlusername->setText(user_name);
    ui->sqlpassword->setText(pass_wd);
    ui->databasename->setText(database_name);
}

dsqlip::~dsqlip()
{
    delete ui;
}

void dsqlip::on_pushButton_2_clicked()
{
    this->close();
}

void dsqlip::on_pushButton_clicked()
{
    //ok
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
        this->close();
    }
    else
    {
        QMessageBox::warning(this,QString("messages"),"Cannot connect to the database");
    }
}
