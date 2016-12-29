#include "vipstudent.h"

VIPStudent::VIPStudent(const QString &hid,const QString &hpassword,const QString &hname
           ,const QString &hbirth, const QString &hsex,const int level, const QString &hdept
           ,const int hmax_num,const double hdebt):
    student(hid, hpassword, hname, hbirth,hsex,level, hdept, hmax_num, hdebt)
{

}

VIPStudent::VIPStudent(const QString &id):student(id)
{

}
