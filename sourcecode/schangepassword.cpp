#include "schangepassword.h"
#include "ui_schangepassword.h"

schangepassword::schangepassword(QWidget *parent,student *ss) :
    QDialog(parent),s(ss),
    ui(new Ui::schangepassword)
{
    ui->setupUi(this);
}

schangepassword::~schangepassword()
{
    delete ui;
}

void schangepassword::on_pushButton_11_clicked() //ok
{

}

void schangepassword::on_knewpasswordwidget_passwordStatusChanged()
{
    switch (ui->knewpasswordwidget->passwordStatus())
    {
        case KNewPasswordWidget::WeakPassword:
        case KNewPasswordWidget::PasswordNotVerified:
            ui->pushButton_11->setEnabled(false);
            break;
        default:
            ui->pushButton_11->setEnabled(true);
            break;
        }
}

void schangepassword::on_pushButton_clicked()//cancle
{

}
