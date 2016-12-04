#include "finemanager.h"
#include "ui_finemanager.h"

finemanager::finemanager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::finemanager)
{
    ui->setupUi(this);

    QSqlQuery query(QSqlDatabase::database("myconnection"));

    query.exec("select @maxday;");
    QString s1(query.value(0).toString());
    ui->lineEdit->setText(s1);

    query.exec("select @finerate;");

    ui->lineEdit_2->setText(query.value(0).toString());

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
    query.exec("set @maxday ="+ ui->lineEdit->text());
    query.exec("set @finerate ="+ui->lineEdit_2->text());
    this->hide();
}
