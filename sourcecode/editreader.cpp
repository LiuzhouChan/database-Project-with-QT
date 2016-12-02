#include "editreader.h"
#include "ui_editreader.h"

editreader::editreader(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editreader)
{
    ui->setupUi(this);
}

editreader::~editreader()
{
    delete ui;
}
