#include "modifybook.h"
#include "ui_modifybook.h"

modifybook::modifybook(QWidget *parent, book *boo,manager *man) :
    QWidget(parent),b(boo),m(man),
    ui(new Ui::modifybook)
{
    ui->setupUi(this);
    ui->lineEdit->setText(b->get_name());
    ui->lineEdit_2->setText(b->get_isbn());
    ui->lineEdit_3->setText(b->get_auther());
    ui->lineEdit_4->setText(b->get_sno());
    ui->kdatecombobox->setDate(QDate::fromString(b->get_date(),"yyyy-MM-dd"));
    ui->lineEdit_6->setText(b->get_price());
    ui->lineEdit_9->setText(b->get_bookno());
    ui->lineEdit_7->setText(b->get_publish());
    if(b->get_state()=="NULL")//in library
    {
        ui->lineEdit_8->setText("sno:"+b->get_sno());
        ui->lineEdit_8->setReadOnly(false);
        ui->radioButton->setVisible(false);
        ui->radioButton_3->setVisible(false);
    }
    else//in student
    {
        ui->lineEdit_8->setText("stuid:"+b->get_state());
        ui->radioButton_2->setVisible(false);
        ui->lineEdit->setReadOnly(true);
        ui->lineEdit_7->setReadOnly(true);
        ui->lineEdit_6->setReadOnly(true);
        ui->lineEdit_4->setReadOnly(true);
        ui->lineEdit_3->setReadOnly(true);
        ui->lineEdit_2->setReadOnly(true);
    }
}

modifybook::~modifybook()
{
    delete b;
    delete ui;
}

void modifybook::on_pushButton_3_clicked()
{
    this->hide();
}

void modifybook::on_pushButton_2_clicked()
{

    if(ui->radioButton_2->isChecked())
    {
        m->modifybook(*b,ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),
                      ui->lineEdit_4->text(),ui->kdatecombobox->date().toString(),ui->lineEdit_6->text()
                      ,ui->lineEdit_9->text(),ui->lineEdit_7->text(),"NULL");
        m->
    }
}
