#ifndef DNEWREADER_H
#define DNEWREADER_H

#include <QDialog>
#include "student.h"
#include <QLineEdit>
#include <QRadioButton>
#include <QSpinBox>
#include <kdatecombobox.h>
#include <QMessageBox>
#include "msfactory.h"
namespace Ui {
class dnewreader;
}

class dnewreader : public QDialog
{
    Q_OBJECT

public:
    explicit dnewreader(QWidget *parent,MSfactory *mf);
    ~dnewreader();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    MSfactory *mf;
    Ui::dnewreader *ui;
};

#endif // DNEWREADER_H
