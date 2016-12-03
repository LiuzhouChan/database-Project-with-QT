#ifndef STUDENTMAINWINDOW_H
#define STUDENTMAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <memory>
#include <QTableWidget>
#include <QStringList>
#include <QHeaderView>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QComboBox>
#include <QRadioButton>
#include <QLineEdit>
#include "student.h"
namespace Ui {
class studentMainWindow;
}

class studentMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit studentMainWindow(QWidget *parent,student *stu);
    ~studentMainWindow();

private slots:
    void on_pushButton_clicked();

private:
    student * stud;
    Ui::studentMainWindow *ui;
    void settable(QSqlQuery &query);
    void settable2(QSqlQuery &query);

};

#endif // STUDENTMAINWINDOW_H
