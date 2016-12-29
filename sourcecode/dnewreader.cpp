#include "dnewreader.h"
#include "ui_dnewreader.h"

dnewreader::dnewreader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dnewreader)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    ui->spinBox->setValue(5);
    ui->radioButton->setChecked(true);
}

dnewreader::~dnewreader()
{
    delete ui;
}

void dnewreader::on_pushButton_3_clicked()
{
    this->close();
}

void dnewreader::on_pushButton_2_clicked()
{
    //ok
    if(ui->lineEdit->text().isEmpty()||ui->lineEdit_2->text().isEmpty()||ui->lineEdit_3->text().isEmpty()||
            ui->lineEdit_6->text().isEmpty()||ui->kratingwidget->rating()==0)
    {
        QMessageBox::about(this,"loss of info","You should edit all the lines");
        return;
    }
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select * from Reader where Rno=\""+ui->lineEdit_2->text()+"\"");
    if(query.next())
    {
        QMessageBox::about(this,"Reader","This Reader number is already used, please try another one");
        return;
    }
    int sex;
    if(ui->radioButton->isChecked())
    {
        sex=0;
    }
    else
    {
        sex=1;
    }
    ManagerStudentFactory mf;
    student *s = mf.createStudent(ui->lineEdit_2->text(),ui->lineEdit_3->text(),
                     ui->lineEdit->text(),ui->kdatecombobox->date().toString("yyyy-MM-dd"),QString::number(sex),
                                  ui->kratingwidget->rating()
                     ,ui->lineEdit_6->text(),ui->spinBox->value(),0);
    s->save_new();
    delete s;
    QMessageBox::about(this,"Add new reader","Successful");
    this->close();

}
