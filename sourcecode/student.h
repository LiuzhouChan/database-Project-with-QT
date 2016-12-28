#ifndef STUDENT_H
#define STUDENT_H
#include <QString>
#include "account.h"
#include <QSqlQuery>
#include "book.h"
#include <QDate>
#include <QDateTime>
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
    virtual ~student();
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
    virtual void save()const;    //change the information of student
    virtual void save_new()const; //insert a new student

    virtual int borrowBook(const account &a, book &b);
    virtual void returnBook(const account &a, book &b);
    virtual int renewBook(const account &a, book &b);
};

#endif // STUDENT_H
