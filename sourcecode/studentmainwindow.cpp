#include "studentmainwindow.h"
#include "ui_studentmainwindow.h"

studentMainWindow::studentMainWindow(QWidget *parent,student * ss) :
    QMainWindow(parent),stud(ss),
    ui(new Ui::studentMainWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    on_pushButton_5_clicked();
}


studentMainWindow::~studentMainWindow()
{
    delete stud;
    delete ui;
}

void studentMainWindow::on_pushButton_clicked()
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    QStringList header;
    header<<"Name"<<"ISBN"<<"Publisher"<<"Author"<<"Data"<<"Price"<<"Shelf"
         <<"Status";

    if(ui->lineEdit->text().isEmpty())
    {
        ui->tableWidget->clear();
        int i(0);
        if(ui->radioButton->isChecked())
        {
            query.exec("select Book.Bname,Book.ISBN,Book.Bpublisher,"
                       "Book.Bauthor,Book.Bdate,Book.Bprice,Book.Sno,count("
                       "Book.ISBN) from Book join BookForRent on "
                       "Book.ISBN=BookForRent.ISBN WHERE Bposi is NULL group by Book.ISBN having count(Book.ISBN)>0;");
        }
        else
        {
            query.exec("select Book.Bname,Book.ISBN,Book.Bpublisher,"
                       "Book.Bauthor,Book.Bdate,Book.Bprice,Book.Sno,count("
                       "Book.ISBN) from Book join BookForRent on "
                       "Book.ISBN=BookForRent.ISBN group by Book.ISBN;");
        }
        i=settable(query,ui->tableWidget,header,i);
        rmrow(i,ui->tableWidget);
        ui->tableWidget->show();
        return;
    }

    if(ui->comboBox->currentText()=="BookName")
    {
        ui->tableWidget->clear();
        int i(0);
        if(ui->radioButton->isChecked())
        {
            query.exec("select Book.Bname,Book.ISBN,Book.Bpublisher,"
                       "Book.Bauthor,Book.Bdate,Book.Bprice,Book.Sno,count("
                       "Book.ISBN) from Book join BookForRent on "
                       "Book.ISBN=BookForRent.ISBN where Book.Bname =\""+
                       ui->lineEdit->text()+"\" and Bposi is NULL group by Book.ISBN having count(Book.ISBN)>0;");
        }
        else
        {
            query.exec("select Book.Bname,Book.ISBN,Book.Bpublisher,"
                       "Book.Bauthor,Book.Bdate,Book.Bprice,Book.Sno,count("
                       "Book.ISBN) from Book join BookForRent on "
                       "Book.ISBN=BookForRent.ISBN where Book.Bname =\""+
                       ui->lineEdit->text()+"\" group by Book.ISBN;");
        }
        i=settable(query,ui->tableWidget,header,i);
        rmrow(i,ui->tableWidget);
    }
    else if(ui->comboBox->currentText()=="Author")
    {
        ui->tableWidget->clear();
        int i(0);
        if(ui->radioButton->isChecked())
        {
            query.exec("select Book.Bname,Book.ISBN,Book.Bpublisher,"
                       "Book.Bauthor,Book.Bdate,Book.Bprice,Book.Sno,count("
                       "Book.ISBN) from Book join BookForRent on "
                       "Book.ISBN=BookForRent.ISBN where Book.Bauthor =\""+
                       ui->lineEdit->text()+"\" and Bposi is NULL group by Book.ISBN having count(Book.ISBN)>0;");
        }
        else
        {
            query.exec("select Book.Bname,Book.ISBN,Book.Bpublisher,"
                       "Book.Bauthor,Book.Bdate,Book.Bprice,Book.Sno,count("
                       "Book.ISBN) from Book join BookForRent on "
                       "Book.ISBN=BookForRent.ISBN where Book.Bauthor =\""+
                       ui->lineEdit->text()+"\" group by Book.ISBN;");
        }
        i=settable(query,ui->tableWidget,header,i);
        rmrow(i,ui->tableWidget);
    }
    else
    {
        ui->tableWidget->clear();
        int i(0);
        if(ui->radioButton->isChecked())
        {
            query.exec("select Book.Bname,Book.ISBN,Book.Bpublisher,"
                       "Book.Bauthor,Book.Bdate,Book.Bprice,Book.Sno,count("
                       "Book.ISBN) from Book join BookForRent on "
                       "Book.ISBN=BookForRent.ISBN where Book.ISBN =\""+
                       ui->lineEdit->text()+"\" and Bposi is NULL group by Book.ISBN having count(Book.ISBN)>0;");
        }
        else
        {
            query.exec("select Book.Bname,Book.ISBN,Book.Bpublisher,"
                       "Book.Bauthor,Book.Bdate,Book.Bprice,Book.Sno,count("
                       "Book.ISBN) from Book join BookForRent on "
                       "Book.ISBN=BookForRent.ISBN where Book.ISBN =\""+
                       ui->lineEdit->text()+"\" group by Book.ISBN;");
        }
        i=settable(query,ui->tableWidget,header,i);
        rmrow(i,ui->tableWidget);
    }
    ui->tableWidget->show();
}

void studentMainWindow::on_pushButton_2_clicked()
{
    if(stud->get_debt()>0)
    {
        QMessageBox::about(this,"debt","You are in debt");
        return;
    }
    if(stud->get_booknum()==stud->get_max())
    {
        QMessageBox::about(this,"book number","You can not borrow more books, please return some fist");
        return;
    }
    int row=ui->tableWidget->currentRow();
    if(row>-1)
    {
        QString isbn=ui->tableWidget->item(row,1)->text();
        QSqlQuery query(QSqlDatabase::database("myconnection"));
        query.exec("SELECT Bno from BookForRent where ISBN= \""+isbn+"\" and Bposi is NULL");
        QString bno;
        if(query.next())
        {
            bno=query.value(0).toString();
        }
        if(bno.isEmpty())
        {
            QMessageBox::about(this,"no book","All this kind of books are not in library");
        }
        else
        {
            book *b=new book(bno);
            stud->borrowBook(*stud,*b);
            QMessageBox::about(this,"Borrow book","successfully borrow this book");
            delete b;
            on_pushButton_clicked();
        }

    }
}

void studentMainWindow::on_pushButton_13_clicked()
{
    schangepassword *sc=new schangepassword(this,stud);
    sc->show();
}

void studentMainWindow::on_pushButton_3_clicked() //return books
{
    int row=ui->tableWidget_2->currentRow();
    if(row>-1)
    {
        book b(ui->tableWidget_2->item(row,1)->text());
        stud->returnBook(*stud,b);
        on_pushButton_5_clicked();
        ui->lineEdit_8->setText(QString::number(stud->get_debt()));
    }
}

void studentMainWindow::on_pushButton_5_clicked()//refresh
{
    //personal info display
    if(stud->get_sex()=="0")
    {
        ui->radioButton_3->setChecked(true);
    }
    else
    {
        ui->radioButton_4->setChecked(true);
    }
    ui->kratingwidget->setRating(stud->get_level());
    ui->kratingwidget->setEnabled(false);
    ui->lineEdit_3->setText(stud->get_name());
    ui->lineEdit_4->setText(stud->get_id());
    ui->kdatecombobox->setDate(QDate::fromString(stud->get_birth(),"yyyy-MM-dd"));
    ui->lineEdit_6->setText(stud->get_dept());
    ui->lineEdit_7->setText(QString::number(stud->get_max()));
    ui->lineEdit_8->setText(QString::number(stud->get_debt()));


    QStringList header;
    header<<"Name"<<"Book NO."<<"Start date"<<"Due date";
    ui->tableWidget_2->clear();
    ui->tableWidget_2->setColumnCount(header.size());
    ui->tableWidget_2->setHorizontalHeaderLabels(header);
    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);
    int i(0);
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select Book.Bname,BookForRent.Bno from Book,BookForRent where "
               "Book.ISBN=BookForRent.ISBN and BookForRent.Bposi=\""+stud->get_id()+"\"");

    while(query.next())
    {
        if(ui->tableWidget_2->rowCount()<i+1)
        {
            ui->tableWidget_2->insertRow(i);
        }
        QString name=query.value(0).toString();
        QString booknumber=query.value(1).toString();
        QString brno;
        QDateTime startday=ulastborrow(brno,booknumber);
        QDateTime dueday=startday.addDays(umaxday());
        ui->tableWidget_2->setItem(i,0,new QTableWidgetItem(name));
        ui->tableWidget_2->setItem(i,1,new QTableWidgetItem(booknumber));
        ui->tableWidget_2->setItem(i,2,new QTableWidgetItem(startday.toString("yyyy-MM-dd HH:mm:ss")));
        ui->tableWidget_2->setItem(i,3,new QTableWidgetItem(dueday.toString("yyyy-MM-dd HH:mm:ss")));
        ++i;
   }
    rmrow(i,ui->tableWidget_2);
    ui->tableWidget_2->show();

    //jieshu huanshu
    i=0;
    QStringList bheader;
    bheader<<"流水号"<<"操作者"<<"书编号"<<"借书时间";
    query.exec("select BRno,operNo,Bno,startTime from BorrowRecord where Rno = \""+stud->get_id()+"\"");
    ui->tableWidget_3->clear();
    i=settable(query,ui->tableWidget_3,bheader,i);
    rmrow(i,ui->tableWidget_3);

    //huan shu
    i=0;
    QStringList hheader;
    hheader<<"流水号"<<"操作者"<<"书编号"<<"还书时间";
    query.exec("SELECT ReturnRecord.RRno,ReturnRecord.operNo,BorrowRecord.Bno,ReturnRecord.returnTime "
               "FROM ReturnRecord,BorrowRecord "
               "WHERE ReturnRecord.BRno=BorrowRecord.BRno "
               "AND BorrowRecord.Rno = \""+stud->get_id()+"\"");
    ui->tableWidget_4->clear();
    i=settable(query,ui->tableWidget_4,hheader,i);
    rmrow(i,ui->tableWidget_4);

    //xujie
    i=0;
    QStringList rheader;
    rheader<<"流水号"<<"操作者"<<"书编号"<<"续借时间";
    query.exec("SELECT renewrecord.NRno,renewrecord.operNo,BorrowRecord.Bno,renewrecord.restartTime "
               "FROM renewrecord,BorrowRecord "
               "WHERE renewrecord.BRno=BorrowRecord.BRno "
               "AND BorrowRecord.Rno = \""+stud->get_id()+"\"");
    ui->tableWidget_5->clear();
    i=settable(query,ui->tableWidget_5,rheader,i);
    rmrow(i,ui->tableWidget_5);

    ui->tableWidget_3->show();
    ui->tableWidget_4->show();
    ui->tableWidget_5->show();
}

void studentMainWindow::on_pushButton_4_clicked()  //renew books
{
    if(stud->get_debt()>0)
    {
        QMessageBox::about(this,"debt","You are in debt");
        return;
    }
    int row=ui->tableWidget_2->currentRow();
    if(row>-1)
    {
        book b(ui->tableWidget_2->item(row,1)->text());
        if(QDateTime::currentDateTime()>b.duedate(*stud))
        {
            QMessageBox::about(this,"out of date","This book is out of date and can not been renew");
            return;
        }
        stud->renewBook(*stud,b);
        on_pushButton_5_clicked();
    }
}

void studentMainWindow::on_pushButton_12_clicked()
{
    stud->set_name(ui->lineEdit_3->text());
    stud->set_birth(ui->kdatecombobox->date().toString("yyyy-MM-dd"));
    if(ui->radioButton_3->isChecked())
    {
        stud->set_sex("0");
    }
    else
    {
        stud->set_sex("1");
    }
    stud->set_dept(ui->lineEdit_6->text());
    stud->save();
    QMessageBox::about(this,"change info","successfully change the personal information");
}


