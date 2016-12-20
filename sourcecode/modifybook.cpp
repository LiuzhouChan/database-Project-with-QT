#include "modifybook.h"
#include "ui_modifybook.h"

modifybook::modifybook(QWidget *parent, book *boo, adminMainWindow *pp) :
    QWidget(parent),b(boo),p(pp)
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
    if(b->get_state()=="NULL")
    {
        ui->lineEdit_8->setText(b->get_sno());
    }
    else
    {
        ui->lineEdit_8->setText(b->get_state());
    }
    ui->lineEdit_8->setEnabled(false);
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
    b->set_name(ui->lineEdit->text());
    b->set_isbn(ui->lineEdit_2->text());
    b->set_auther(ui->lineEdit_3->text());
    b->set_sno(ui->lineEdit_4->text());
    b->set_date(ui->kdatecombobox->date().toString());
    b->set_price(ui->lineEdit_6->text());
    b->set_bookno(ui->lineEdit_9->text());
    b->set_publish(ui->lineEdit_7->text());
    b->save();
    p->on_pushButton_5_clicked();
}
