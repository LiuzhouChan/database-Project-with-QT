#include "bookdetail.h"
#include "ui_bookdetail.h"

bookdetail::bookdetail(QWidget *parent,book *boo):
     QWidget(parent),bo(boo),ui(new Ui::bookdetail)
{
    ui->setupUi(this);
    if(bo!=nullptr)
    {

    }
}

bookdetail::~bookdetail()
{
    delete bo;
    delete ui;
}

void bookdetail::on_pushButton_3_clicked()
{
    this->hide();
}

void bookdetail::on_pushButton_2_clicked()
{
    this->hide();
}

void bookdetail::on_pushButton_clicked()
{
    QSqlDatabase db=QSqlDatabase::database("myconnection");
    db.transaction();
    QSqlQuery query(db);
    if(bo==nullptr)
    {
        query.exec(" insert into Book values ("
                   "\""+ui->lineEdit_2->text()+"\","
                   "\""+ui->lineEdit->text()+"\","
                   "\""+ui->lineEdit_9->text()+"\","
                   "\""+ui->lineEdit_8->text()+"\","
                   "\""+ui->lineEdit_3->text()+"\","
                   "\""+ui->lineEdit_5->text()+"\","
                        +ui->lineEdit_6->text()+
                                             ") ");

        query.exec("insert into BookForRent values ("
                   "\""+ui->lineEdit_7->text()+"\","
                   "\""+ui->lineEdit_2->text()+"\","
                   "NULL"
                   ")");
    }
    else
    {

    }

    if(!db.commit())
    {
        QMessageBox::warning(this,"insert error",db.lastError().text()+"errorNumber:"+db.lastError().number());
        db.rollback();
    }

}
