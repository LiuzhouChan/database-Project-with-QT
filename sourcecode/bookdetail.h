#ifndef BOOKDETAIL_H
#define BOOKDETAIL_H

#include <QWidget>

namespace Ui {
class bookdetail;
}

class bookdetail : public QWidget
{
    Q_OBJECT

public:
    explicit bookdetail(QWidget *parent = 0);
    ~bookdetail();

private:
    Ui::bookdetail *ui;
};

#endif // BOOKDETAIL_H
