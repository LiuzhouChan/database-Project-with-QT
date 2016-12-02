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
