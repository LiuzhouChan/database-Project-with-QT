#ifndef DNEWREADER_H
#define DNEWREADER_H

#include <QDialog>
#include "student.h"
#include <QLineEdit>
#include <QRadioButton>
#include <QSpinBox>
#include <kdatecombobox.h>
#include <QMessageBox>
namespace Ui {
class dnewreader;
}

class dnewreader : public QDialog
{
    Q_OBJECT

public:
    explicit dnewreader(QWidget *parent = 0);
    ~dnewreader();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::dnewreader *ui;
};

#endif // DNEWREADER_H
