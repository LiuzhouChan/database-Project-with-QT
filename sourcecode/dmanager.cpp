#include "dmanager.h"
#include "ui_dmanager.h"

dmanager::dmanager(QWidget *parent, manager *mm) :
    QDialog(parent),mm(mm),
    ui(new Ui::dmanager)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    ui->lineEdit_3->setText(mm->get_name());
    ui->lineEdit_4->setText(mm->get_id());
    if(mm->get_sex()=="0")
    {
        ui->radioButton_3->setChecked(true);
    }
    else
    {
        ui->radioButton_4->setChecked(true);
    }
    ui->kdatecombobox->setDate(QDate::fromString(mm->get_birth(),"yyyy-MM-dd"));
}

dmanager::~dmanager()
{
    delete mm;
    delete ui;
}

void dmanager::on_pushButton_clicked()
{
    this->close();
}

void dmanager::on_pushButton_12_clicked()
{
    if(ui->lineEdit_3->text().isEmpty()||ui->lineEdit_4->text().isEmpty())
    {
        return;
    }
    QString sex;
    if(ui->radioButton_3->isChecked())
    {
        sex="0";
    }
    else
    {
        sex="1";
    }
    mm->set_name(ui->lineEdit_3->text());
    mm->set_id(ui->lineEdit_4->text());
    mm->set_sex(sex);
    mm->set_birth(ui->kdatecombobox->date().toString("yyyy-MM-dd"));
    mm->save();
    this->close();
}

void dmanager::on_pushButton_13_clicked()
{
    dchangepassword *dc=new dchangepassword(this,mm);
    dc.show();
}
