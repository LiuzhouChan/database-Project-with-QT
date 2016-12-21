#include "dnewbook.h"
#include "ui_dnewbook.h"

dnewbook::dnewbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dnewbook)
{
    ui->setupUi(this);
}

dnewbook::~dnewbook()
{
    delete ui;
}

void dnewbook::on_pushButton_3_clicked()
{
    this->close();
}

void dnewbook::on_pushButton_2_clicked()
{
    //ok
    book b(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text()
           ,ui->lineEdit_4->text(),ui->kdatecombobox->date().toString(),ui->lineEdit_6->text(),
           ui->lineEdit_9->text(),ui->lineEdit_7->text(),"null");
    b.save_new();
    this->close();
}
