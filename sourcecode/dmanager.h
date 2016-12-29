#ifndef DMANAGER_H
#define DMANAGER_H

#include <QDialog>
#include "manager.h"
#include <QString>
#include <QLineEdit>
#include <QRadioButton>
#include "dchangepassword.h"

namespace Ui {
class dmanager;
}

class dmanager : public QDialog
{
    Q_OBJECT

public:
    explicit dmanager(QWidget *parent, manager * mm);
    ~dmanager();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

private:
    manager * mm;
    Ui::dmanager *ui;
};

#endif // DMANAGER_H
