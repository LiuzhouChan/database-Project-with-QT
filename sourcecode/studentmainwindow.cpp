#include "studentmainwindow.h"
#include "ui_studentmainwindow.h"

studentMainWindow::studentMainWindow(QWidget *parent) :
    QMainWindow(parent),stud(nullptr),
    ui(new Ui::studentMainWindow)
{

}

void studentMainWindow::setstu(student *ss)
{
    stud=ss;
}

void studentMainWindow::refresh()
{
    QStringList header;
    header<<"Name"<<"ISBN";
    ui->tableWidget_2->clear();
    QSqlQuery query(QSqlDatabase::database("myconnection"));
//    int maxday;
//    query.exec("select maxday from Fine");
//    if(query.next())
//    {
//        maxday=query.value(0).toInt();
//    }
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
        for(int j=0;j<size;++j)
        {
               ui->tableWidget_2->setItem(i,j,
                  new QTableWidgetItem(query.value(j).toString()));
        }
           ++i;
   }
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
