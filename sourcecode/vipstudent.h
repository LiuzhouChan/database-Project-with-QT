#ifndef VIPSTUDENT_H
#define VIPSTUDENT_H
#include "student.h"

class VIPStudent:public student
{
public:
    VIPStudent(const QString &hid,const QString &hpassword,const QString &hname
               ,const QString &hbirth, const QString &hsex,const int level, const QString &hdept
               ,const int hmax_num,const double hdebt);
};

#endif // VIPSTUDENT_H
