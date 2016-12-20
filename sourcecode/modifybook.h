#ifndef MODIFYBOOK_H
#define MODIFYBOOK_H

#include <QWidget>
#include "book.h"
#include <QLineEdit>
#include <kdatecombobox.h>
#include "adminmainwindow.h"

namespace Ui {
class modifybook;
}

class modifybook : public QWidget
{
    Q_OBJECT

public:
    explicit modifybook(QWidget *parent = 0, book *boo=nullptr, adminMainWindow *pp);
    ~modifybook();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    adminMainWindow *p;
    book *b;
    Ui::modifybook *ui;
};

#endif // MODIFYBOOK_H
