#include "finemanager.h"
#include "ui_finemanager.h"

finemanager::finemanager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::finemanager)
{
    ui->setupUi(this);

    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select * from Fine;");
    if(query.next())
    {
        ui->lineEdit->setText(query.value(0).toString());
        ui->lineEdit_2->setText(query.value(1).toString());
    }


}

finemanager::~finemanager()
{
    delete ui;
}

void finemanager::on_pushButton_2_clicked()
{
    this->hide();
}

void finemanager::on_pushButton_clicked()
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("update Fine set maxday ="+ ui->lineEdit->text());
    query.exec("update Fine set rate ="+ui->lineEdit_2->text());
    this->hide();
}
