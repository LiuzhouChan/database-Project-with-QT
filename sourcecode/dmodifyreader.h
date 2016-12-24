#ifndef DMODIFYREADER_H
#define DMODIFYREADER_H

#include <QDialog>
#include <QLineEdit>
#include <QSqlQuery>
#include "student.h"
#include "manager.h"
#include <kdatecombobox.h>
#include <QRadioButton>
#include <QSpinBox>
#include <QMessageBox>
namespace Ui {
class dmodifyreader;
}

class dmodifyreader : public QDialog
{
    Q_OBJECT

public:
    explicit dmodifyreader(QWidget *parent,student *ss,manager *mm);
    ~dmodifyreader();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    student *s;
    manager *m;
    Ui::dmodifyreader *ui;
};

#endif // DMODIFYREADER_H
