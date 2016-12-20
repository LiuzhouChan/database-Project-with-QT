#ifndef MODIFYBOOK_H
#define MODIFYBOOK_H

#include <QWidget>
#include "book.h"
#include <QLineEdit>
#include <kdatecombobox.h>
#include "manager.h"
#include <QPushButton>
#include <QRadioButton>
namespace Ui {
class modifybook;
}

class modifybook : public QWidget
{
    Q_OBJECT

public:
    explicit modifybook(QWidget *parent, book *boo,manager *man);
    ~modifybook();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    manager * m;
    book *b;
    Ui::modifybook *ui;
};

#endif // MODIFYBOOK_H
