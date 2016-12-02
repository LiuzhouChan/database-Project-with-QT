#ifndef EDITREADER_H
#define EDITREADER_H

#include <QWidget>

namespace Ui {
class editreader;
}

class editreader : public QWidget
{
    Q_OBJECT

public:
    explicit editreader(QWidget *parent = 0);
    ~editreader();

private:
    Ui::editreader *ui;
};

#endif // EDITREADER_H
