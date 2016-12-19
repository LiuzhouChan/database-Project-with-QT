#include "modifybook.h"
#include "ui_modifybook.h"

modifybook::modifybook(QWidget *parent,book *boo) :
    QWidget(parent),b(boo),
    ui(new Ui::modifybook)
{
    ui->setupUi(this);
    ui->lineEdit->setText(b->get_name());
    ui->lineEdit_2->setText(b->get_isbn());
    ui->lineEdit_3->setText(b->get_auther());
    ui->lineEdit_4->setText(b->get_type());
    ui->lineEdit_5->setText(b->get_date());
    ui->lineEdit_6->setText(b->get_price());
    ui->lineEdit_9->setText(b->get_bookno());
    ui->lineEdit_7->setText(b->get_publish());
    if(b->get_state()=="null")
    {
        ui->lineEdit_8->setText(b->get_position());
    }
    else
    {
        ui->lineEdit_8->setText(b->get_state());
    }
    ui->lineEdit_8->setDisabled(true);
}

modifybook::~modifybook()
{
    delete ui;
}

void modifybook::on_pushButton_3_clicked()
{
    this->hide();
}

void modifybook::on_pushButton_2_clicked()
{
    b->set_name(ui->lineEdit->text());
    b->set_isbn(ui->lineEdit_2->text());
    b->set_auther(ui->lineEdit_3->text());
    b->set_type(ui->lineEdit_4->text());
    b->set_date(ui->lineEdit_5->text());
    b->set_price(ui->lineEdit_6->text());
    b->set_bookno(ui->lineEdit_9->text());
    b->set_publish(ui->lineEdit_7->text());
    b->save();
}
