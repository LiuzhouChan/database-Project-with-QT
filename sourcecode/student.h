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
#include "reader.h"
class student:public account
{
private:
    QString dept;
    int max_num;
    int num;
    double debt;
public:
    student(const QString & id);
    student(const QString &hid,const QString &hpassword,const QString &hname
            ,const QString &hbirth, const QString &hsex,const int level, const QString &hdept
            ,const int hmax_num,const double hdebt);

    void set_dept(const QString &s);
    void set_debt(const double s);
    void set_max(const int s);

    QString get_dept()const;
    double get_debt()const;
    int get_max()const;
    int get_booknum() const;
    void save()const;    //change the information of student
    void save_new()const; //insert a new student

    void borrowBook(const account &a, book &b);
    void returnBook(const account &a, book &b);
    void renewBook(const account &a, book &b);
};

#endif // STUDENT_H
