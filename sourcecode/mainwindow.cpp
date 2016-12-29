#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ip=new dsqlip(this);
}

MainWindow::~MainWindow()
{
    if(QSqlDatabase::contains("myconnection"))
    {
       QSqlDatabase::database("myconnection").close();
       QSqlDatabase::removeDatabase("myconnection");
    }
    delete ip;
    delete ui;
}

void MainWindow::on_actionSQL_server_IP_triggered()
{
    ip->show();
}

void MainWindow::on_actionAbout_QT_triggered()
{
    QMessageBox::aboutQt(this,"About QT");
}

void MainWindow::on_loginButton_clicked()
{
    int login=0;
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select * from Reader where Rno=\""+ui->lineEdit_2->text()+"\"");
    if(query.next())
    {
        if(query.value(1).toString()==ui->lineEdit_3->text())
        {
            login=1;
            this->hide();

            ManagerStudentFactory mf;
            if(query.value(8).toString()=="0")//if it is manager
            {
                manager *man=mf.createManager(ui->lineEdit_2->text());
                adminMainWindow *admin = new adminMainWindow(this,man);
                admin->show();
            }
            else    //student
            {
                student *stu=mf.createStudent(ui->lineEdit_2->text());
                studentMainWindow *studen=new studentMainWindow(this,stu);
                studen->show();
            }
        }

    }


    if(login==0)
    {
        ui->statusBar->showMessage("Either the username or password is uncorrect",5000);
    }
}
