#ifndef EDITREADER_H
#define EDITREADER_H

#include <QWidget>
#include <QtWidgets>
#include "student.h"
#include <QLineEdit>
#include <QRadioButton>
#include <QSpinBox>
#include <kdatecombobox.h>
namespace Ui {
class editreader;
}

class editreader : public QWidget
{
    Q_OBJECT
public:
    explicit editreader(QWidget *parent = 0);
    ~editreader();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::editreader *ui;
};

#endif // EDITREADER_H
