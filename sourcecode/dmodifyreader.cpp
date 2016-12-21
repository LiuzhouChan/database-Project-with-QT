#include "dmodifyreader.h"
#include "ui_dmodifyreader.h"

dmodifyreader::dmodifyreader(QWidget *parent, student *ss, manager *mm) :
    QDialog(parent),s(ss),m(mm),
    ui(new Ui::dmodifyreader)
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

dmodifyreader::~dmodifyreader()
{
    delete s;
    delete ui;
}

void dmodifyreader::on_pushButton_clicked()
{
    ui->lineEdit_8->setText("0");
}

void dmodifyreader::on_pushButton_2_clicked()
{

}

void dmodifyreader::on_pushButton_3_clicked()
{
    this->close();
}
