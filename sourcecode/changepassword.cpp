
#include "changepassword.h"
#include "ui_changepassword.h"

changepassword::changepassword(QWidget *parent, manager *mang) :
    QWidget(parent), man(mang),
    ui(new Ui::changepassword)
{
    ui->setupUi(this);
}

changepassword::~changepassword()
{
    delete ui;
}

void changepassword::on_pushButton_2_clicked()
{
    this->hide();
}

void changepassword::on_pushButton_clicked()
{
    if(ui->lineEdit->text()==man->passwd)
    {
        man->passwd=ui->knewpasswordwidget->password();
        QSqlQuery query(QSqlDatabase::database("myconnection"));
        query.exec("update Manager set password = \""
                       +man->passwd+"\" where Mon = \""+
                       man->id+"\"");
        QMessageBox::information(this,"password","Change the password successfully");
        this->hide();
    }
    else
    {
        QMessageBox::information(this,"password","the old password is not correct");
    }
}

void changepassword::on_knewpasswordwidget_passwordStatusChanged()
{
    switch (ui->knewpasswordwidget->passwordStatus())
    {
        case KNewPasswordWidget::WeakPassword:
        case KNewPasswordWidget::PasswordNotVerified:
            ui->pushButton->setEnabled(false);
            break;
        default:
            ui->pushButton->setEnabled(true);
            break;
        }
}
