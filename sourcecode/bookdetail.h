#ifndef BOOKDETAIL_H
#define BOOKDETAIL_H

#include <QWidget>
#include "book.h"
#include <QLineEdit>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QPushButton>
namespace Ui {
class bookdetail;
}

class bookdetail : public QWidget
{
    Q_OBJECT

public:
    explicit bookdetail(QWidget *parent=0,book * boo=nullptr);
    ~bookdetail();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    book *bo;
    Ui::bookdetail *ui;
};

#endif // BOOKDETAIL_H
