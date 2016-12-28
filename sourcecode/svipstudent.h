#ifndef SVIPSTUDENT_H
#define SVIPSTUDENT_H
#include "vipstudent.h"

class SVIPStudent:public VIPStudent
{
public:
    SVIPStudent(const QString &hid, const QString &hpassword, const QString &hname,
                const QString &hbirth, const QString &hsex, const int level, const QString
                &hdept, const int hmax_num, const double hdebt);
};

#endif // SVIPSTUDENT_H
