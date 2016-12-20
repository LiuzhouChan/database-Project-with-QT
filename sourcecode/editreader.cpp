#include "editreader.h"
#include "ui_editreader.h"

editreader::editreader(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editreader)
{
    ui->setupUi(this);
    ui->radioButton->setChecked(true);
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

    int sex;
    if(ui->radioButton->isChecked())
    {
        sex=0;
    }
    else
    {
        sex=1;
    }
    student s(ui->lineEdit_2->text(),ui->lineEdit_3->text(),
              ui->lineEdit->text(),ui->kdatecombobox->data().toString(),QString::number(sex)
              ,ui->lineEdit_6->text(),ui->spinBox->value(),0);
    s.save_new();
    this->hide();
}
