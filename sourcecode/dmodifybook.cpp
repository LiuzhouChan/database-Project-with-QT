#include "dmodifybook.h"
#include "ui_dmodifybook.h"

dmodifybook::dmodifybook(QWidget *parent, book *boo, manager *man, MSfactory *mf):
    QDialog(parent),b(boo),m(man),mf(mf),
    ui(new Ui::dmodifybook)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    ui->comboBox->setCurrentText(b->get_type());
    ui->lineEdit->setText(b->get_name());
    ui->lineEdit_2->setText(b->get_isbn());
    ui->lineEdit_3->setText(b->get_auther());
    ui->kdatecombobox->setDate(QDate::fromString(b->get_date(),"yyyy-MM-dd"));
    ui->lineEdit_6->setText(b->get_price());
    ui->lineEdit_9->setText(b->get_bookno());
    ui->lineEdit_7->setText(b->get_publish());
    if(b->get_state()=="NULL")//in library
    {
        ui->lineEdit_8->setText("shelf:"+b->get_sno());
        ui->lineEdit_8->setReadOnly(false);
        ui->radioButton->setVisible(false);
        ui->radioButton_3->setVisible(false);
    }
    else//in student
    {
        ui->kdatecombobox->setEnabled(false);
        ui->lineEdit_8->setText("student id:"+b->get_state());
        ui->radioButton_2->setVisible(false);
        ui->lineEdit->setReadOnly(true);
        ui->lineEdit_7->setReadOnly(true);
        ui->lineEdit_6->setReadOnly(true);
        ui->lineEdit_3->setReadOnly(true);
        ui->lineEdit_2->setReadOnly(true);
        ui->lineEdit_9->setReadOnly(true);
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
        QSqlQuery query(QSqlDatabase::database("myconnection"));
        query.exec("select * from BookForRent where Bno=\""+ui->lineEdit_9->text()+"\"");
        if(query.next()&&ui->lineEdit_9->text()!=b->get_bookno())
        {
            QMessageBox::about(this,"book","This book number is already used, please try another one");
            return;
        }
        m->modifybook(*b,ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),
                      ui->comboBox->currentText(),ui->kdatecombobox->date().toString("yyyy-MM-dd"),ui->lineEdit_6->text()
                      ,ui->lineEdit_9->text(),ui->lineEdit_7->text(),"NULL");

        query.exec("select * from Reader where Rno=\""+ui->lineEdit_8->text()+"\"");
        if(!query.next())
        {
            QMessageBox::about(this,"reader","There is no Reader who's number is "+ui->lineEdit_8->text());
            return;
        }
        Reader *s=ReaderFactory::createReader(mf,ui->lineEdit_8->text());
        int re(m->borrowbook(s,b));
        if(re==1)
        {
            QMessageBox::about(this,"debt","Can not borrow this book since this reader is in debt");
        }
        else if(re==2)
        {
            QMessageBox::about(this,"book number",
                              "Can not borrow this book since this student in max borrow number");
        }
        else
        {
            QMessageBox::about(this,"borrow book","sucessful");
        }
        delete s;
    }
    if(ui->radioButton->isChecked()) //return book
    {
        Reader *s=ReaderFactory::createReader(mf,b->get_state());
        m->returnbook(s,b);
        delete s;
    }
    if(ui->radioButton_3->isChecked()) //renew book
    {
        Reader *s=ReaderFactory::createReader(mf,b->get_state());
        int re(m->renewbook(s,b));
        if(re==1)
        {
            QMessageBox::about(this,"debt","Can not renew this book since this student is in debt");
        }
        else if(re==2)
        {
            QMessageBox::about(this,"out of date","Can not renew this book since this book is out of date");
        }
        else
        {
            QMessageBox::about(this,"Renew book", "sucessfully");
        }
        delete s;
    }
    else
    {
        QSqlQuery query(QSqlDatabase::database("myconnection"));
        query.exec("select * from BookForRent where Bno=\""+ui->lineEdit_9->text()+"\"");
        if(query.next()&&ui->lineEdit_9->text()!=b->get_bookno())
        {
            QMessageBox::about(this,"book","This book number is already used, please try another one");
            return;
        }
        m->modifybook(*b,ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),
                      ui->comboBox->currentText(),ui->kdatecombobox->date().toString("yyyy-MM-dd"),ui->lineEdit_6->text()
                      ,ui->lineEdit_9->text(),ui->lineEdit_7->text(),"NULL");
    }
    this->close();
}
