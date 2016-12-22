#ifndef ADMINMAINWINDOW_H
#define ADMINMAINWINDOW_H
#include <QMainWindow>
#include <QMessageBox>
#include <QCheckBox>
#include <QSqlQuery>
#include "manager.h"
#include <QTableWidget>
#include <QLineEdit>
#include <util.h>
#include <QComboBox>
#include "dfinemanager.h"
#include "dchangepassword.h"
#include <QAction>
#include "dnewreader.h"
#include "dnewbook.h"
#include "dmodifybook.h"
#include "dmodifyreader.h"

namespace Ui {
class adminMainWindow;
}

class adminMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminMainWindow(QWidget *parent);
    ~adminMainWindow();
    void setManager(manager *mang);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_action_triggered();

    void on_action_2_triggered();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_17_clicked();

private:
    Ui::adminMainWindow *ui;
    manager *man;
};

#endif // ADMINMAINWINDOW_H
