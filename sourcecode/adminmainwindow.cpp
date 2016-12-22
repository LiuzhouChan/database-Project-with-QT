#include "adminmainwindow.h"
#include "ui_adminmainwindow.h"

adminMainWindow::adminMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminMainWindow),man(nullptr)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

void adminMainWindow::setManager(manager *mang)
{
    man=mang;
}

adminMainWindow::~adminMainWindow()
{
    this->parentWidget()->show();
    delete ui;
}


void adminMainWindow::on_pushButton_clicked()
{
     QSqlQuery query(QSqlDatabase::database("myconnection"));
     QStringList header;
     header<<"Name"<<"ISBN"<<"Publisher"<<"Author"<<"Data"<<"Price"<<"BookNumber"
          <<"Status";
     if(ui->lineEdit->text().isEmpty())
     {
             ui->tableWidget->clear();
             int i(0);
             if(ui->checkBox_3->isChecked())
             {
                 query.exec("select Book.Bname,Book.ISBN,Book.Bpublisher,"
                            "Book.Bauthor,Book.Bdate,Book.Bprice,BookForRent.Bno,Book.Sno"
                            " from Book join BookForRent on "
                            "Book.ISBN=BookForRent.ISBN where BookForRent.Bposi is null;");
                 i=settable(query,ui->tableWidget,header,i);
             }
            if(ui->checkBox_4->isChecked())
             {
                query.exec("select Book.Bname,Book.ISBN,Book.Bpublisher,"
                           "Book.Bauthor,Book.Bdate,Book.Bprice,BookForRent.Bno,BookForRent.Bposi"
                           " from Book join BookForRent on "
                           "Book.ISBN=BookForRent.ISBN where BookForRent.Bposi is not null;");
                i=settable(query,ui->tableWidget,header,i);
             }
            rmrow(i,ui->tableWidget);
            ui->tableWidget->show();
            return;
     }

     if(ui->comboBox->currentText()=="BookName")
     {
         ui->tableWidget->clear();
         int i(0);
         if(ui->checkBox_3->isChecked())
         {
             query.exec("select Book.Bname,Book.ISBN,Book.Bpublisher,"
                        "Book.Bauthor,Book.Bdate,Book.Bprice,BookForRent.Bno,Book.Sno"
                        " from Book join BookForRent on "
                        "Book.ISBN=BookForRent.ISBN where Book.Bname = \""+
                        ui->lineEdit->text()+"\" and BookForRent.Bposi is null;");
             i=settable(query,ui->tableWidget,header,i);
         }
        if(ui->checkBox_4->isChecked())
         {
            query.exec("select Book.Bname,Book.ISBN,Book.Bpublisher,"
                       "Book.Bauthor,Book.Bdate,Book.Bprice,BookForRent.Bno,BookForRent.Bposi"
                       " from Book join BookForRent on "
                       "Book.ISBN=BookForRent.ISBN where Book.Bname = \""+
                       ui->lineEdit->text()+"\" and BookForRent.Bposi is not null;");
            i=settable(query,ui->tableWidget,header,i);
         }
        rmrow(i,ui->tableWidget);
     }
     else if(ui->comboBox->currentText()=="Author")
     {
         ui->tableWidget->clear();
         int i(0);
         if(ui->checkBox_3->isChecked())
         {
             query.exec("select Book.Bname,Book.ISBN,Book.Bpublisher,"
                        "Book.Bauthor,Book.Bdate,Book.Bprice,BookForRent.Bno,Book.Sno"
                        " from Book join BookForRent on "
                        "Book.ISBN=BookForRent.ISBN where Book.Bauthor = \""+
                        ui->lineEdit->text()+"\" and BookForRent.Bposi is null;");
             i=settable(query,ui->tableWidget,header,i);
         }
        if(ui->checkBox_4->isChecked())
         {
            query.exec("select Book.Bname,Book.ISBN,Book.Bpublisher,"
                       "Book.Bauthor,Book.Bdate,Book.Bprice,BookForRent.Bno,BookForRent.Bposi"
                       " from Book join BookForRent on "
                       "Book.ISBN=BookForRent.ISBN where Book.Bauthor = \""+
                       ui->lineEdit->text()+"\" and BookForRent.Bposi is not null;");
            i=settable(query,ui->tableWidget,header,i);
         }
        rmrow(i,ui->tableWidget);
     }
     else if(ui->comboBox->currentText()=="ISBN")
     {
         ui->tableWidget->clear();
         int i(0);
         if(ui->checkBox_3->isChecked())
         {
             query.exec("select Book.Bname,Book.ISBN,Book.Bpublisher,"
                        "Book.Bauthor,Book.Bdate,Book.Bprice,BookForRent.Bno,Book.Sno"
                        " from Book join BookForRent on "
                        "Book.ISBN=BookForRent.ISBN where Book.ISBN =\""+
                        ui->lineEdit->text()+"\" and BookForRent.Bposi is null;");
             i=settable(query,ui->tableWidget,header,i);
         }
        if(ui->checkBox_4->isChecked())
         {
            query.exec("select Book.Bname,Book.ISBN,Book.Bpublisher,"
                       "Book.Bauthor,Book.Bdate,Book.Bprice,BookForRent.Bno,BookForRent.Bposi"
                       " from Book join BookForRent on "
                       "Book.ISBN=BookForRent.ISBN where Book.ISBN =\""+
                       ui->lineEdit->text()+"\" and BookForRent.Bposi is not null;");
            i=settable(query,ui->tableWidget,header,i);
         }
        rmrow(i,ui->tableWidget);
     }
     else
     {
         ui->tableWidget->clear();
         int i(0);
         if(ui->checkBox_4->isChecked())
         {
             query.exec("select Book.Bname,Book.ISBN,Book.Bpublisher,"
                        "Book.Bauthor,Book.Bdate,Book.Bprice,BookForRent.Bno,BookForRent.Bposi"
                        " from Book join BookForRent on "
                        "Book.ISBN=BookForRent.ISBN where BookForRent.Bposi =\""+ui->lineEdit->text()+"\" ");
             i=settable(query,ui->tableWidget,header,i);
         }
         rmrow(i,ui->tableWidget);
     }
     ui->tableWidget->show();
}


void adminMainWindow::on_pushButton_5_clicked()
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    QStringList header;
    header<<"Id"<<"password"<<"Name"<<"Birth"<<"Sex"<<"Dept"<<"Max borrow number"
         <<"Debt";


    if(ui->lineEdit_2->text().isEmpty())
    {
        ui->tableWidget_2->clear();
        int i(0);
        if(ui->checkBox->isChecked())
        {
            query.exec("select * from Reader where Rdebt > 0;");
            i=settable(query,ui->tableWidget_2,header,i);
        }
       if(ui->checkBox_2->isChecked())
        {
           query.exec("select * from Reader where Rdebt = 0;");
           i=settable(query,ui->tableWidget_2,header,i);
        }
       rmrow(i,ui->tableWidget_2);
       ui->tableWidget_2->show();
       return;
    }
    if(ui->comboBox_2->currentText()=="ID")
    {
        ui->tableWidget_2->clear();
        int i(0);
        if(ui->checkBox->isChecked())
        {
            query.exec("select * from Reader where Rno = \""+
                       ui->lineEdit_2->text()+"\" and Rdebt > 0;");
            i=settable(query,ui->tableWidget_2,header,i);
        }
       if(ui->checkBox_2->isChecked())
        {
           query.exec("select * from Reader where Rno = \""+
                      ui->lineEdit_2->text()+"\" and Rdebt = 0;");
           i=settable(query,ui->tableWidget_2,header,i);
        }
       rmrow(i,ui->tableWidget_2);
    }
    else
    {
        ui->tableWidget_2->clear();
        int i(0);
        if(ui->checkBox->isChecked())
        {
            query.exec("select * from Reader where Rname = \""+
                       ui->lineEdit_2->text()+"\" and Rdebt > 0;");
            i=settable(query,ui->tableWidget_2,header,i);
        }
       if(ui->checkBox_2->isChecked())
        {
           query.exec("select * from Reader where Rname = \""+
                      ui->lineEdit_2->text()+"\" and Rdebt = 0;");
           i=settable(query,ui->tableWidget_2,header,i);
        }
       rmrow(i,ui->tableWidget_2);
    }
     ui->tableWidget_2->show();
}

void adminMainWindow::on_action_triggered()
{
    dfinemanager *fin=new dfinemanager(this);
    fin->show();
}

void adminMainWindow::on_action_2_triggered()
{
    dchangepassword *ch=new dchangepassword(this,man);
    ch->show();
}

void adminMainWindow::on_pushButton_4_clicked()
{
     dnewbook *book=new dnewbook(this);
     book->show();
}

void adminMainWindow::on_pushButton_6_clicked()
{
    dnewreader *e=new dnewreader(this);
    e->show();
}

void adminMainWindow::on_pushButton_3_clicked()
{
    int row=ui->tableWidget->currentRow();
    if(row>=0)
    {
        QString bno=ui->tableWidget->item(row,6)->text();

    //    QSqlQuery query(QSqlDatabase::database("myconnection"));
    //    query.exec("select Book.Bname,Book.ISBN,Book.Bauthor,Book.Sno,"
    //               "Book.Bdate,Book.Bprice,Book.Bpublisher,"
    //               "BookForRent.Bposi"
    //               " from Book,BookForRent where BookForRent.ISBN=Book.ISBN and "
    //               "BookForRent.Bno=\""+bno+"\"");
    //    book *b;
    //    if(query.next())
    //    {
    //        b=new book(query.value(0).toString(),query.value(1).toString(),
    //                         query.value(2).toString(),query.value(3).toString(),
    //                         query.value(4).toString(),query.value(5).toString(),
    //                         bno,query.value(6).toString(),query.value(7).toString());
    //    }


        dmodifybook *mb=new dmodifybook(this,new book(bno),man);
        mb->show();
    }

}

void adminMainWindow::on_pushButton_7_clicked()
{
    int row=ui->tableWidget_2->currentRow();
    if(row>=0)
    {
        student *s = new student(ui->tableWidget_2->item(row,0)->text());
    //    student *s = new student(ui->tableWidget_2->item(row,0)->text(),ui->tableWidget_2->item(row,1)->text(),
    //                             ui->tableWidget_2->item(row,2)->text(),ui->tableWidget_2->item(row,3)->text(),
    //                             ui->tableWidget_2->item(row,4)->text(),ui->tableWidget_2->item(row,5)->text(),
    //                             ui->tableWidget_2->item(row,6)->text().toInt(),
    //                             ui->tableWidget_2->item(row,7)->text().toDouble());
        dmodifyreader *m=new dmodifyreader(this,s,man);
        m->show();
    }

}

void adminMainWindow::on_pushButton_8_clicked()
{
    int row=ui->tableWidget_2->currentRow();
    if(row>=0)
    {
        man->deletReader(ui->tableWidget_2->item(row,0)->text());
        on_pushButton_5_clicked();
    }

}

void adminMainWindow::on_pushButton_2_clicked()
{
    int row=ui->tableWidget->currentRow();
    if(row>=0)
    {
        man->deleteBook(ui->tableWidget->item(row,1)->text());
        on_pushButton_clicked();
    }

}

void adminMainWindow::on_pushButton_17_clicked()
{
    if(ui->lineEdit_5->text().isEmpty())
    {
        //jieshu huanshu
        i=0;
        QStringList bheader;
        bheader<<"流水号"<<"操作者"<<"读者"<<"书编号"<<"借书时间";
        query.exec("select BRno,operNo,Rno,Bno,startTime from BorrowRecord");
        ui->tableWidget_3->clear();
        i=settable(query,ui->tableWidget_3,bheader,i);
        rmrow(i,ui->tableWidget_3);

        //huan shu
        i=0;
        QStringList hheader;
        hheader<<"流水号"<<"操作者"<<"读者"<<"书编号"<<"还书时间";
        query.exec("SELECT ReturnRecord.RRno,ReturnRecord.operNo,BorrowRecord.Rno,BorrowRecord.Bno,ReturnRecord.returnTime "
                   "FROM ReturnRecord,BorrowRecord "
                   "WHERE ReturnRecord.BRno=BorrowRecord.BRno ");
        ui->tableWidget_7->clear();
        i=settable(query,ui->tableWidget_7,hheader,i);
        rmrow(i,ui->tableWidget_7);

        //xujie
        i=0;
        QStringList hheader;
        hheader<<"流水号"<<"操作者"<<"读者"<<"书编号"<<"续借时间";
        query.exec("SELECT renewrecord.NRno,renewrecord.operNo,BorrowRecord.Bno,renewrecord.restartTime "
                   "FROM renewrecord,BorrowRecord "
                   "WHERE renewrecord.BRno=BorrowRecord.BRno ");
        ui->tableWidget_8->clear();
        i=settable(query,ui->tableWidget_8,hheader,i);
        rmrow(i,ui->tableWidget_8);
    }
    else if(ui->comboBox_5->currentText()=="student id")
    {
        //jieshu huanshu
        i=0;
        QStringList bheader;
        bheader<<"流水号"<<"操作者"<<"读者"<<"书编号"<<"借书时间";
        query.exec("select BRno,operNo,Rno,Bno,startTime from BorrowRecord where Rno = \""+ui->lineEdit_5->text()+"\"");
        ui->tableWidget_3->clear();
        i=settable(query,ui->tableWidget_3,bheader,i);
        rmrow(i,ui->tableWidget_3);

        //huan shu
        i=0;
        QStringList hheader;
        hheader<<"流水号"<<"操作者"<<"读者"<<"书编号"<<"还书时间";
        query.exec("SELECT ReturnRecord.RRno,ReturnRecord.operNo,BorrowRecord.Rno,BorrowRecord.Bno,ReturnRecord.returnTime "
                   "FROM ReturnRecord,BorrowRecord "
                   "WHERE ReturnRecord.BRno=BorrowRecord.BRno "
                   "AND where BorrowRecord.Rno = \""+ui->lineEdit_5->text()+"\"");
        ui->tableWidget_7->clear();
        i=settable(query,ui->tableWidget_7,hheader,i);
        rmrow(i,ui->tableWidget_7);

        //xujie
        i=0;
        QStringList hheader;
        hheader<<"流水号"<<"操作者"<<"读者"<<"书编号"<<"续借时间";
        query.exec("SELECT renewrecord.NRno,renewrecord.operNo,BorrowRecord.Bno,renewrecord.restartTime "
                   "FROM renewrecord,BorrowRecord "
                   "WHERE renewrecord.BRno=BorrowRecord.BRno "
                   "AND where BorrowRecord.Rno = \""+ui->lineEdit_5->text()+"\"");
        ui->tableWidget_8->clear();
        i=settable(query,ui->tableWidget_8,hheader,i);
        rmrow(i,ui->tableWidget_8);
    }
    else  //bno
    {
        //jieshu huanshu
        i=0;
        QStringList bheader;
        bheader<<"流水号"<<"操作者"<<"读者"<<"书编号"<<"借书时间";
        query.exec("select BRno,operNo,Rno,Bno,startTime from BorrowRecord where Bno = \""+ui->lineEdit_5->text()+"\"");
        ui->tableWidget_3->clear();
        i=settable(query,ui->tableWidget_3,bheader,i);
        rmrow(i,ui->tableWidget_3);

        //huan shu
        i=0;
        QStringList hheader;
        hheader<<"流水号"<<"操作者"<<"读者"<<"书编号"<<"还书时间";
        query.exec("SELECT ReturnRecord.RRno,ReturnRecord.operNo,BorrowRecord.Rno,BorrowRecord.Bno,ReturnRecord.returnTime "
                   "FROM ReturnRecord,BorrowRecord "
                   "WHERE ReturnRecord.BRno=BorrowRecord.BRno "
                   "AND where BorrowRecord.Bno = \""+ui->lineEdit_5->text()+"\"");
        ui->tableWidget_7->clear();
        i=settable(query,ui->tableWidget_7,hheader,i);
        rmrow(i,ui->tableWidget_7);

        //xujie
        i=0;
        QStringList hheader;
        hheader<<"流水号"<<"操作者"<<"读者"<<"书编号"<<"续借时间";
        query.exec("SELECT renewrecord.NRno,renewrecord.operNo,BorrowRecord.Bno,renewrecord.restartTime "
                   "FROM renewrecord,BorrowRecord "
                   "WHERE renewrecord.BRno=BorrowRecord.BRno "
                   "AND where BorrowRecord.Bno = \""+ui->lineEdit_5->text()+"\"");
        ui->tableWidget_8->clear();
        i=settable(query,ui->tableWidget_8,hheader,i);
        rmrow(i,ui->tableWidget_8);
    }
    ui->tableWidget_3->show();
    ui->tableWidget_7->show();
    ui->tableWidget_8->show();

}
