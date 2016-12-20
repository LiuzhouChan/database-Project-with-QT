#ifndef EDITBOOK_H
#define EDITBOOK_H

#include <QWidget>
#include "book.h"
#include <QLineEdit>
#include <kdatecombobox.h>
#include "adminmainwindow.h"
namespace Ui {
class editbook;
}

class editbook : public QWidget
{
    Q_OBJECT

public:
    explicit editbook(QWidget *parent = 0,adminMainWindow *pp);
    ~editbook();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    adminMainWindow *p;
    Ui::editbook *ui;
};

#endif // EDITBOOK_H