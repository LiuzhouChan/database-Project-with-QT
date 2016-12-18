#ifndef STUDENT_H
#define STUDENT_H
#include <QString>
#include "manager.h"
class student:public manager
{
private:
    QString name;
    QString birth;
    QString sex;
    QString dept;
    int debt;
public:
    student(const QString &hid,const QString &hpassword,const QString &hname
            ,const QString &hbirth, const QString &hsex, const QString &hdept
            ,const int hdebt);

    void set_name(const QString &s);
    void set_birth(const QString &s);
    void set_sex(const QString &s);
    void set_dept(const QString &s);
    void set_debt(const int s);

    QString get_name();
    QString get_birth();
    QString get_sex();
    QString get_dept();
    int get_debt();

    void save();    //change the information of student
    void save_new(); //insert a new student

};

#endif // STUDENT_H
