#include "schangepassword.h"
#include "ui_schangepassword.h"

schangepassword::schangepassword(QWidget *parent,student *ss) :
    QDialog(parent),s(ss),
    ui(new Ui::schangepassword)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

}

schangepassword::~schangepassword()
{
    delete ui;
}

void schangepassword::on_pushButton_11_clicked() //ok
{
    if(ui->lineEdit_13->text()==s->get_passwd())
    {
        s->set_passwd(ui->knewpasswordwidget->password());
        s->save();
        QMessageBox::information(this,"password","Change the password successfully");
        this->close();
    }
    else
    {
        QMessageBox::information(this,"password","the old password is not correct");
    }
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
    this->close();
}
