#ifndef STUDENT_H
#define STUDENT_H
#include <QString>
#include "manager.h"
class student:public manager
{
public:
    student(QString hid,QString hpassword,QString hname
            ,QString hbirth, QString hsex, QString hdept
            ,int hmax_number,double hdebt);
    QString name;
    QString birth;
    QString sex;
    QString dept;
    int max_number;
    double debt;
};

#endif // STUDENT_H
