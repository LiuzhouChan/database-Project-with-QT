#ifndef STUDENT_H
#define STUDENT_H
#include <QString>
#include "account.h"
#include <QSqlQuery>
#include "book.h"
#include <QDate>
#include "brrowrecord.h"
#include "returnrecord.h"
#include "renewrecord.h"

class student:public account
{
private:
    QString name;
    QString birth;
    QString sex;
    QString dept;
    int max_num;
    double debt;
public:
    student(const QString &hid,const QString &hpassword,const QString &hname
            ,const QString &hbirth, const QString &hsex, const QString &hdept
            ,const int hmax_num,const double hdebt);

    void set_name(const QString &s);
    void set_birth(const QString &s);
    void set_sex(const QString &s);
    void set_dept(const QString &s);
    void set_debt(const double s);
    void set_max(const int s);

    QString get_name()const;
    QString get_birth()const;
    QString get_sex()const;
    QString get_dept()const;
    double get_debt()const;
    int get_max()const;
    void save()const;    //change the information of student
    void save_new()const; //insert a new student

    void borrowBook(const account &a, book &b);
    void returnBook(const account &a, book &b);
    void renewBook(const account &a, book &b);
};

#endif // STUDENT_H
