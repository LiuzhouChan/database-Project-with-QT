#ifndef SCHANGEPASSWORD_H
#define SCHANGEPASSWORD_H

#include <QDialog>
#include "student.h"
namespace Ui {
class schangepassword;
}

class schangepassword : public QDialog
{
    Q_OBJECT

public:
    explicit schangepassword(QWidget *parent,student *ss);
    ~schangepassword();

private slots:
    void on_pushButton_11_clicked();
    void on_knewpasswordwidget_passwordStatusChanged();
    void on_pushButton_clicked();

private:
    student *s;
    Ui::schangepassword *ui;
};

#endif // SCHANGEPASSWORD_H
