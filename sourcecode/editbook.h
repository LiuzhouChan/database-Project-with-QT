#ifndef EDITBOOK_H
#define EDITBOOK_H

#include <QWidget>

namespace Ui {
class editbook;
}

class editbook : public QWidget
{
    Q_OBJECT

public:
    explicit editbook(QWidget *parent = 0);
    ~editbook();

private:
    Ui::editbook *ui;
};

#endif // EDITBOOK_H
