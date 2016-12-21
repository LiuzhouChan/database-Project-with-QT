#ifndef DFINEMANAGER_H
#define DFINEMANAGER_H

#include <QDialog>
#include <QSqlQuery>
#include <QLineEdit>
#include <QString>
namespace Ui {
class dfinemanager;
}

class dfinemanager : public QDialog
{
    Q_OBJECT

public:
    explicit dfinemanager(QWidget *parent = 0);
    ~dfinemanager();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::dfinemanager *ui;
};

#endif // DFINEMANAGER_H
