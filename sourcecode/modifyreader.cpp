#include "modifyreader.h"
#include "ui_modifyreader.h"

modifyreader::modifyreader(QWidget *parent,student *ss,manager *mm) :
    QWidget(parent),s(ss),m(mm),
    ui(new Ui::modifyreader)
{
    ui->setupUi(this);
    ui->lineEdit->setText(s->get_name());
    ui->lineEdit_2->setText(s->get_id());
    ui->lineEdit_2->setEnabled(false);
    ui->lineEdit_3->setText(s->get_passwd());
    ui->lineEdit_4->setText(s->get_birth());
    ui->lineEdit_5->setText(s->get_sex());
    ui->lineEdit_6->setText(s->get_dept());
    ui->lineEdit_7->setText(QString::number(s->get_max()));
    ui->lineEdit_8->setText(QString::number(s->get_debt()));
    ui->lineEdit_8->setEnabled(false);
}

modifyreader::~modifyreader()
{
    delete ui;
}

void modifyreader::on_pushButton_3_clicked()
{
    this->hide();
}

void modifyreader::on_pushButton_2_clicked()
{
    m->modifyreader(*s,ui->lineEdit_3->text(),ui->lineEdit->text(),ui->lineEdit_4->text()
                    ,ui->lineEdit_5->text(),
                    ui->lineEdit_6->text(),ui->lineEdit_7->text().toInt(),ui->lineEdit_8->text().toDouble());
}

void modifyreader::on_pushButton_clicked()
{
    ui->lineEdit_8->setText("0");
}
