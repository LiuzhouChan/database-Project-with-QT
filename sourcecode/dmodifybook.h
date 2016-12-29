#ifndef DMODIFYBOOK_H
#define DMODIFYBOOK_H

#include <QDialog>
#include "book.h"
#include <QLineEdit>
#include <kdatecombobox.h>
#include "manager.h"
#include <QPushButton>
#include <QRadioButton>
#include <QMessageBox>
#include "readerfactory.h"
#include "msfactory.h"
namespace Ui {
class dmodifybook;
}

class dmodifybook : public QDialog
{
    Q_OBJECT

public:
    explicit dmodifybook(QWidget *parent,book *boo,manager *man,MSfactory *mf);
    ~dmodifybook();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    book *b;
    manager * m;
    MSfactory *mf;
    Ui::dmodifybook *ui;
};

#endif // DMODIFYBOOK_H
