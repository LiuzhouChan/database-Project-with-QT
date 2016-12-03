#ifndef BOOKDETAIL_H
#define BOOKDETAIL_H

#include <QWidget>
#include "book.h"
namespace Ui {
class bookdetail;
}

class bookdetail : public QWidget
{
    Q_OBJECT

public:
    explicit bookdetail(QWidget *parent,book * boo);
    ~bookdetail();

private:
    Ui::bookdetail *ui;
    book *bo;
};

#endif // BOOKDETAIL_H
