#include "dmodifyreader.h"
#include "ui_dmodifyreader.h"

dmodifyreader::dmodifyreader(QWidget *parent, student *ss, manager *mm) :
    QDialog(parent),s(ss),m(mm),
    ui(new Ui::dmodifyreader)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    ui->lineEdit->setText(s->get_name());
    ui->lineEdit_2->setText(s->get_id());
    ui->lineEdit_3->setText(s->get_passwd());
    ui->kdatecombobox->setDate(QDate::fromString(s->get_birth(),"yyyy-MM-dd"));
    if(s->get_sex()=="0")
    {
        ui->radioButton->setChecked(true);
    }
    else
    {
        ui->radioButton_2->setChecked(true);
    }
    ui->lineEdit_6->setText(s->get_dept());
    ui->spinBox->setValue(s->get_max());
    ui->lineEdit_8->setText(QString::number(s->get_debt()));
}

dmodifyreader::~dmodifyreader()
{
    delete s;
    delete ui;
}

void dmodifyreader::on_pushButton_clicked()
{
    ui->lineEdit_8->setText("0");
}

void dmodifyreader::on_pushButton_2_clicked()
{
    QString sex;
    if(ui->radioButton->isChecked())
    {
        sex="0";
    }
    if(ui->radioButton_2->isChecked())
    {
        sex="1";
    }

    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select * from Reader where Rno=\""+ui->lineEdit_2->text()+"\"");
    if(query.next())
    {
        QMessageBox::about(this,"Reader","This Reader number is already used, please try another one");
        return;
    }
    m->modifyreader(*s,ui->lineEdit_3->text(),ui->lineEdit->text(),ui->kdatecombobox->date().toString("yyyy-MM-dd"),
                    sex,ui->lineEdit_6->text(),ui->spinBox->value(),ui->lineEdit_8->text().toDouble());
    this->close();
}

void dmodifyreader::on_pushButton_3_clicked()
{
    this->close();
}
