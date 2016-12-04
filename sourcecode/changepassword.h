#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QWidget>
#include <QLineEdit>
#include "manager.h"
#include <QMessageBox>
#include <QSqlQuery>
namespace Ui {
class changepassword;
}

class changepassword : public QWidget
{
    Q_OBJECT

public:
    explicit changepassword(QWidget *parent,manager *mang);
    ~changepassword();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_knewpasswordwidget_passwordStatusChanged();

private:
    manager *man;
    Ui::changepassword *ui;
};

#endif // CHANGEPASSWORD_H
