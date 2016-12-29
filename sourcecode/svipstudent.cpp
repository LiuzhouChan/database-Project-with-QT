#include "svipstudent.h"

SVIPStudent::SVIPStudent(const QString &hid,const QString &hpassword,const QString &hname
                         ,const QString &hbirth, const QString &hsex,const int level, const QString &hdept
                         ,const int hmax_num,const double hdebt):
    VIPStudent(hid,hpassword,hname,hbirth,hsex,level,hdept,hmax_num,hdebt)
{

}

SVIPStudent::SVIPStudent(const QString &id):VIPStudent(id)
{

}
