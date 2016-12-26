#include "dnewbook.h"
#include "ui_dnewbook.h"

dnewbook::dnewbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dnewbook)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

dnewbook::~dnewbook()
{
    delete ui;
}

void dnewbook::on_pushButton_3_clicked()
{
    this->close();
}

void dnewbook::on_pushButton_2_clicked()
{
    //ok
    if(ui->lineEdit->text().isEmpty()||ui->lineEdit_2->text().isEmpty()||ui->lineEdit_3->text().isEmpty()||
            ui->lineEdit_4->text().isEmpty()||ui->lineEdit_6->text().isEmpty()||ui->lineEdit_7->text().isEmpty()||
            ui->lineEdit_9->text().isEmpty())
    {
        QMessageBox::about(this,"loss of info","You should edit all the lines");
        return;
    }
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select * from BookForRent where Bno=\""+ui->lineEdit_9->text()+"\"");
    if(query.next())
    {
        QMessageBox::about(this,"book","This book number is already used, please try another one");
        return;
    }
    query.exec("select * from Shelf where Sno=\""+ui->lineEdit_4->text()+"\"");
    if(!query.next())
    {
        QMessageBox::about(this,"shelf","This is no shelf of number "+ui->lineEdit_4->text());
        return;
    }
    book b(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text()
           ,ui->lineEdit_4->text(),ui->kdatecombobox->date().toString("yyyy-MM-dd"),ui->lineEdit_6->text(),
           ui->lineEdit_9->text(),ui->lineEdit_7->text(),"null");
    b.save_new();
    QMessageBox::about(this,"add new book","successful");
    this->close();
}
