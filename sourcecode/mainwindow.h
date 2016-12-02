#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sqlip.h"
#include <QString>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionSQL_server_IP_triggered();

    void on_actionAbout_QT_triggered();

private:
    Ui::MainWindow *ui;
    sqlip *ip;
};

#endif // MAINWINDOW_H
