#ifndef DCHANGEPASSWORD_H
#define DCHANGEPASSWORD_H

#include <QDialog>
#include <QWidget>
#include <QLineEdit>
#include "manager.h"
#include <QMessageBox>
#include <QSqlQuery>
namespace Ui {
class dchangepassword;
}

class dchangepassword : public QDialog
{
    Q_OBJECT

public:
    explicit dchangepassword(QWidget *parent,manager *mang);
    ~dchangepassword();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_knewpasswordwidget_passwordStatusChanged();
private:
    manager *man;
    Ui::dchangepassword *ui;
};

#endif // DCHANGEPASSWORD_H
