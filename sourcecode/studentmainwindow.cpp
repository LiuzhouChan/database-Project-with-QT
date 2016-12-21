#include "studentmainwindow.h"
#include "ui_studentmainwindow.h"

studentMainWindow::studentMainWindow(QWidget *parent) :
    QMainWindow(parent),stud(nullptr),
    ui(new Ui::studentMainWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
   // refresh();
}

void studentMainWindow::setstu(student *ss)
{
    stud=ss;
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

//    int settable(QSqlQuery &query,QTableWidget* table, QStringList &header,int i);
//    void rmrow(int i,QTableWidget * table);
    if(ui->lineEdit->text().isEmpty())
    {
        ui->tableWidget->clear();
        int i(0);
        if(ui->radioButton->isChecked())
        {
            query.exec("select Book.Bname,Book.ISBN,Book.Bpublisher,"
                       "Book.Bauthor,Book.Bdate,Book.Bprice,Book.Sno,count("
                       "Book.ISBN) from Book join BookForRent on "
                       "Book.ISBN=BookForRent.ISBN group by Book.ISBN having count(Book.ISBN)>0;");
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
                       ui->lineEdit->text()+"\" group by Book.ISBN having count(Book.ISBN)>0;");
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
                       ui->lineEdit->text()+"\" group by Book.ISBN having count(Book.ISBN)>0;");
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
                       ui->lineEdit->text()+"\" group by Book.ISBN having count(Book.ISBN)>0;");
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

//void studentMainWindow::settable2(QSqlQuery &query)
//{
//    ui->tableWidget_2->clear();
//    QStringList header;
//    header<<"Name"<<"ISBN"<<"Publisher"<<"Author"<<"Date"<<"Price"<<"Start date"<<"Due data"<<"Fine";
//   // std::unique_ptr<QTableView>
//    ui->tableWidget_2->setColumnCount(9);
//    ui->tableWidget_2->setHorizontalHeaderLabels(header);
//    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);

//    int i=0;
//    while(query.next())
//    {

//        if(ui->tableWidget_2->rowCount()<i+1)
//        {
//            ui->tableWidget_2->insertRow(i);
//        }
//        for(int j=0;j<9;++j)
//        {
//            ui->tableWidget_2->setItem(i,j,
//                   new QTableWidgetItem(query.value(j).toString()));
//        }
//         ++i;
//    }
//    int num=ui->tableWidget_2->rowCount();
//    for(int jj=0;jj<num-i;++jj)
//    {
//        ui->tableWidget_2->removeRow(i);
//    }
//}
//void studentMainWindow::settable(QSqlQuery &query)
//{
//    ui->tableWidget->clear();
//    QStringList header;
//    header<<"Name"<<"ISBN"<<"Publisher"<<"Author"<<"Data"<<"Price"<<"Shelf"
//         <<"Status";
//   // std::unique_ptr<QTableView>
//    ui->tableWidget->setColumnCount(8);
//    ui->tableWidget->setHorizontalHeaderLabels(header);
//    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

//    int i=0;
//    while(query.next())
//    {

//        if(ui->tableWidget->rowCount()<i+1)
//        {
//            ui->tableWidget->insertRow(i);
//        }
//        for(int j=0;j<8;++j)
//        {
//            ui->tableWidget->setItem(i,j,
//                   new QTableWidgetItem(query.value(j).toString()));
//        }
//         ++i;
//    }
//    int num=ui->tableWidget->rowCount();
//    for(int jj=0;jj<num-i;++jj)
//    {
//        ui->tableWidget->removeRow(i);
//    }
//}

void studentMainWindow::on_pushButton_2_clicked()
{
    int row=ui->tableWidget->currentRow();
    QString isbn=ui->tableWidget->item(row,1)->text();
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("SELECT Bno from BookForRent where ISBN= \""+isbn+"\" and Bposi is NULL");
    QString bno;
    if(query.next())
    {
        bno=query.value(0).toString();
    }
    book *b=new book(bno);
    stud->borrowBook(*stud,*b);
    delete b;

}

void studentMainWindow::on_pushButton_13_clicked()
{

}

void studentMainWindow::on_pushButton_3_clicked()
{

}

void studentMainWindow::on_pushButton_5_clicked()//refresh
{
    QStringList header;
    header<<"Name"<<"Book NO."<<"Start date"<<"Due date";
    ui->tableWidget_2->clear();
    QSqlQuery query(QSqlDatabase::database("myconnection"));

    query.exec("select Book.Bname,BookForRent.Bno from Book,BookForRent where"
               "Book.ISBN=BookForRent.ISBN and BookForRent.Bposi=\""+stud->get_id()+"\"");
    int size(header.size());
    ui->tableWidget_2->setColumnCount(size);
    ui->tableWidget_2->setHorizontalHeaderLabels(header);
    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);
    int i(0);
    while(query.next())
    {
        if(ui->tableWidget_2->rowCount()<i+1)
        {
            ui->tableWidget_2->insertRow(i);
        }
        QString name=query.value(0).toString();
        QString booknumber=query.value(1).toString();
        QString brno;
        QDate startday=ulastborrow(brno,booknumber);
        QDate dueday=startday.addDays(umaxday());
        ui->tableWidget_2->setItem(i,0,new QTableWidgetItem(name));
        ui->tableWidget_2->setItem(i,1,new QTableWidgetItem(booknumber));
        ui->tableWidget_2->setItem(i,2,new QTableWidgetItem(startday.toString()));
        ui->tableWidget_2->setItem(i,3,new QTableWidgetItem(dueday.toString()));
        ++i;
   }
    rmrow(i,ui->tableWidget_2);
    ui->tableWidget_2->show();
}
