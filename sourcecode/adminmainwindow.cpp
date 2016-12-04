#include "adminmainwindow.h"
#include "ui_adminmainwindow.h"

adminMainWindow::adminMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminMainWindow),man(nullptr)
{
    ui->setupUi(this);
}

void adminMainWindow::setManager(manager *mang)
{
    man=mang;
}

adminMainWindow::~adminMainWindow()
{
    delete man;
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
     else
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
    finemanager *fin=new finemanager;
    fin->show();
}

void adminMainWindow::on_action_2_triggered()
{
    changepassword *ch=new changepassword(0,man);
    ch->show();
}

void adminMainWindow::on_pushButton_4_clicked()
{
    bookdetail *book=new bookdetail;
    book->show();
}
