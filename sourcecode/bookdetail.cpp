#include "bookdetail.h"
#include "ui_bookdetail.h"

bookdetail::bookdetail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bookdetail)
{
    ui->setupUi(this);
}

bookdetail::~bookdetail()
{
    delete ui;
}
