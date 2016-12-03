#ifndef STUDENTMAINWINDOW_H
#define STUDENTMAINWINDOW_H

#include <QMainWindow>
namespace Ui {
class studentMainWindow;
}

class studentMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit studentMainWindow(QWidget *parent);
    ~studentMainWindow();

private:
    Ui::studentMainWindow *ui;
};

#endif // STUDENTMAINWINDOW_H
