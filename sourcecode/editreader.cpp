#include "editreader.h"
#include "ui_editreader.h"

editreader::editreader(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editreader)
{
    ui->setupUi(this);
}

editreader::~editreader()
{
    delete ui;
}

void editreader::on_pushButton_3_clicked()
{
    this->hide();
}

void editreader::on_pushButton_2_clicked()
{
    student s(ui->lineEdit_2->text(),ui->lineEdit_3->text(),
              ui->lineEdit->text(),ui->lineEdit_4->text(),ui->lineEdit_5->text()
              ,ui->lineEdit_6->text(),ui->lineEdit_7->text().toInt(),0);
    s.save_new();
    this->hide();
}
