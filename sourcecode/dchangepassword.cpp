#include "dchangepassword.h"
#include "ui_dchangepassword.h"

dchangepassword::dchangepassword(QWidget *parent,manager *mang) :
    QDialog(parent),man(mang),
    ui(new Ui::dchangepassword)
{
    ui->setupUi(this);
}

dchangepassword::~dchangepassword()
{
    delete ui;
}

void dchangepassword::on_pushButton_2_clicked()
{
    this->close();
}

void dchangepassword::on_pushButton_clicked()
{
    //ok
    if(ui->lineEdit->text()==man->get_passwd())
    {
        man->set_passwd(ui->knewpasswordwidget->password());
        man->save();
        QMessageBox::information(this,"password","Change the password successfully");
        this->close();
    }
    else
    {
        QMessageBox::information(this,"password","the old password is not correct");
    }
}


void dchangepassword::on_knewpasswordwidget_passwordStatusChanged()
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
