#ifndef DNEWBOOK_H
#define DNEWBOOK_H

#include <QDialog>
#include "book.h"
#include <QLineEdit>
#include <kdatecombobox.h>
#include "adminmainwindow.h"
#include <QMessageBox>
namespace Ui {
class dnewbook;
}

class dnewbook : public QDialog
{
    Q_OBJECT

public:
    explicit dnewbook(QWidget *parent = 0);
    ~dnewbook();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::dnewbook *ui;
};

#endif // DNEWBOOK_H
