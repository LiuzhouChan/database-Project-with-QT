#include "dfinemanager.h"
#include "ui_dfinemanager.h"

dfinemanager::dfinemanager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dfinemanager)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select * from Fine;");
    if(query.next())
    {
        ui->lineEdit->setText(query.value(0).toString());
        ui->lineEdit_2->setText(query.value(1).toString());
    }
}

dfinemanager::~dfinemanager()
{
    delete ui;
}

void dfinemanager::on_pushButton_2_clicked()
{
    this->close();
}

void dfinemanager::on_pushButton_clicked()
{
    //ok
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("update Fine set maxday ="+ ui->lineEdit->text());
    query.exec("update Fine set rate ="+ui->lineEdit_2->text());
    this->close();
}
