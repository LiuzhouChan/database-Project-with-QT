#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dsqlip.h"
#include <QString>
#include <QMessageBox>
#include "adminmainwindow.h"
#include "studentmainwindow.h"
#include "manager.h"
#include "student.h"
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "msfactory.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent,MSfactory *mf);
    ~MainWindow();

private slots:
    void on_actionSQL_server_IP_triggered();

    void on_actionAbout_QT_triggered();

    void on_loginButton_clicked();

private:
    MSfactory *mf;
    Ui::MainWindow *ui;
    dsqlip *ip;
};

#endif // MAINWINDOW_H
