#ifndef MODIFYREADER_H
#define MODIFYREADER_H

#include <QWidget>
#include <QLineEdit>
#include <QSqlQuery>
#include "student.h"
#include "manager.h"
#include <kdatecombobox.h>
#include <QRadioButton>
#include <QSpinBox>
namespace Ui {
class modifyreader;
}

class modifyreader : public QWidget
{
    Q_OBJECT

public:
    explicit modifyreader(QWidget *parent = 0,student *ss=nullptr,manager *mm=nullptr);
    ~modifyreader();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    student *s;
    manager *m;
    Ui::modifyreader *ui;
};

#endif // MODIFYREADER_H
