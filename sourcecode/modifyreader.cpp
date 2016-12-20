#include "modifyreader.h"
#include "ui_modifyreader.h"

modifyreader::modifyreader(QWidget *parent,student *ss,manager *mm) :
    QWidget(parent),s(ss),m(mm),
    ui(new Ui::modifyreader)
{
    ui->setupUi(this);
    ui->lineEdit->setText(s->get_name());
    ui->lineEdit_2->setText(s->get_id());
    ui->lineEdit_3->setText(s->get_passwd());
    ui->kdatecombobox->setDate(QDate::fromString(s->get_birth(),"yyyy-MM-dd"));
    if(s->get_sex()=="0")
    {
        ui->radioButton->setChecked(true);
    }
    else
    {
        ui->radioButton_2->setChecked(true);
    }
    ui->lineEdit_6->setText(s->get_dept());
    ui->spinBox->setValue(s->get_max());
    ui->lineEdit_8->setText(QString::number(s->get_debt()));
}

modifyreader::~modifyreader()
{
    delete s;
    delete ui;
}

void modifyreader::on_pushButton_3_clicked()
{
    this->hide();
}

void modifyreader::on_pushButton_2_clicked()
{
//    m->modifyreader(*s,ui->lineEdit_3->text(),ui->lineEdit->text(),ui->lineEdit_4->text()
//                    ,ui->lineEdit_5->text(),
//                    ui->lineEdit_6->text(),ui->lineEdit_7->text().toInt(),ui->lineEdit_8->text().toDouble());
}

void modifyreader::on_pushButton_clicked()
{
    ui->lineEdit_8->setText("0");
}
