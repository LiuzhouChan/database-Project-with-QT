#ifndef DSQLIP_H
#define DSQLIP_H

#include <QDialog>
#include <QLineEdit>
#include <QString>
#include <QSql>
#include <QSqlDatabase>
#include <QMessageBox>
namespace Ui {
class dsqlip;
}

class dsqlip : public QDialog
{
    Q_OBJECT

public:
    explicit dsqlip(QWidget *parent = 0);
    ~dsqlip();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::dsqlip *ui;
    QString server_ip;
    QString user_name;
    QString pass_wd;
    QString database_name;
};

#endif // DSQLIP_H
