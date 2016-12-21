#include "dmodifybook.h"
#include "ui_dmodifybook.h"

dmodifybook::dmodifybook(QWidget *parent,book *boo,manager *man):
    QDialog(parent),b(boo),m(man),
    ui(new Ui::dmodifybook)
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
    if(b->get_state()=="")//in library
    {
        ui->lineEdit_8->setText("sno:"+b->get_sno());
        ui->lineEdit_8->setReadOnly(false);
        ui->radioButton->setVisible(false);
        ui->radioButton_3->setVisible(false);
    }
    else//in student
    {
        ui->kdatecombobox->setEnabled(false);
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

dmodifybook::~dmodifybook()
{
    delete b;
    delete ui;
}

void dmodifybook::on_pushButton_3_clicked()
{
    //cancle
    this->close();
}

void dmodifybook::on_pushButton_2_clicked()
{
    //ok
    if(ui->radioButton_2->isChecked())//in library, borrow book
    {
        m->modifybook(*b,ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),
                      ui->lineEdit_4->text(),ui->kdatecombobox->date().toString(),ui->lineEdit_6->text()
                      ,ui->lineEdit_9->text(),ui->lineEdit_7->text(),"NULL");
        student *s = new student(ui->lineEdit_8->text());
        if(s->get_debt()>0)
        {
            QMessageBox::about(this,"debt","Can not borrow this book since this student is in debt");
            delete s;
        }
        else if(s->get_max()<=s->get_booknum())
        {
            QMessageBox::about(this,"book number",
                              "Can not borrow this book since this student in max borrow number");
            delete s;
        }
        else
        {
            m->borrowbook(s,b);
            QMessageBox::about(this,"borrow book",
                              "sucessful");
            delete s;
        }
    }
    if(ui->radioButton->isChecked()) //return book
    {
        student *s=new student(ui->lineEdit_8->text());
        m->returnbook(s,b);
        delete s;
    }
    if(ui->radioButton_3->isChecked()) //renew book
    {
        student *s=new student(ui->lineEdit_8->text());
        if(s->get_debt()>0)
        {
            QMessageBox::about(this,"debt","Can not borrow this book since this student is in debt");
            delete s;
        }
        else
        {
            m->renewbook(s,b);
            QMessageBox::about(this,"borrow book",
                              "sucessful");
            delete s;
        }
    }
    this->close();
}
