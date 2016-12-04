#ifndef FINEMANAGER_H
#define FINEMANAGER_H

#include <QWidget>
#include <QSqlQuery>
#include <QLineEdit>
#include <QString>
namespace Ui {
class finemanager;
}

class finemanager : public QWidget
{
    Q_OBJECT

public:
    explicit finemanager(QWidget *parent=0);
    ~finemanager();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::finemanager *ui;
};

#endif // FINEMANAGER_H
