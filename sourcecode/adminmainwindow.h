#ifndef ADMINMAINWINDOW_H
#define ADMINMAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCheckBox>
#include <QSqlQuery>
#include "manager.h"
#include <QTableWidget>
#include <QLineEdit>
namespace Ui {
class adminMainWindow;
}

class adminMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminMainWindow(QWidget *parent,manager *mang);
    ~adminMainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

private:
    manager *man;
    Ui::adminMainWindow *ui;
    int settable(QSqlQuery &query,QTableWidget *table,QStringList &header,int i);
    void rmrow(int i,QTableWidget* table);
};

#endif // ADMINMAINWINDOW_H
