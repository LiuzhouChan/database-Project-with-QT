#ifndef SQLIP_H
#define SQLIP_H

#include <QDialog>
#include <QLineEdit>
#include <QString>
#include <QSql>
#include <QSqlDatabase>
#include <QMessageBox>

namespace Ui {
class sqlip;
}

class sqlip : public QDialog
{
    Q_OBJECT

public:
    explicit sqlip(QWidget *parent = 0);
    ~sqlip();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::sqlip *ui;
    QString server_ip;
    QString user_name;
    QString pass_wd;
    QString database_name;

};

#endif // SQLIP_H
