#include "editbook.h"
#include "ui_editbook.h"

editbook::editbook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editbook)
{
    ui->setupUi(this);
}

editbook::~editbook()
{
    delete ui;
}

void editbook::on_pushButton_3_clicked()
{
    this->hide();
}

void editbook::on_pushButton_2_clicked()
{
    book b(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text()
           ,ui->lineEdit_4->text(),ui->lineEdit_5->text(),ui->lineEdit_6->text(),
           ui->lineEdit_9->text(),ui->lineEdit_7->text(),"null");
    b.save_new();
    hide();
}
