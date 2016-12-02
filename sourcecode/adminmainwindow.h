#ifndef ADMINMAINWINDOW_H
#define ADMINMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class adminMainWindow;
}

class adminMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminMainWindow(QWidget *parent = 0);
    ~adminMainWindow();

private:
    Ui::adminMainWindow *ui;
};

#endif // ADMINMAINWINDOW_H
