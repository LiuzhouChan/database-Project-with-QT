#include "bookdetail.h"
#include "ui_bookdetail.h"

bookdetail::bookdetail(QWidget *parent,book *boo):
     QWidget(parent),bo(boo),ui(new Ui::bookdetail)
{
    ui->setupUi(this);
}

bookdetail::~bookdetail()
{
    delete bo;
    delete ui;
}
