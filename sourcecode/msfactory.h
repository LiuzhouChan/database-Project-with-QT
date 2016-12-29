#ifndef MSFACTORY_H
#define MSFACTORY_H
#include "student.h"
#include "manager.h"
class manager;
class MSfactory
{
public:
    virtual student* createStudent(const QString &hid,const QString &hpassword,const QString &hname
                                   ,const QString &hbirth, const QString &hsex,const int level, const QString &hdept
                                   ,const int hmax_num,const double hdebt)=0;

    virtual student* createStudent(const QString &hid)=0;

    virtual manager* createManager(const QString &hid,const QString &hpassword,const QString &hname
                                   ,const QString &hbirth, const QString &hsex,const int level)=0;

    virtual manager* createManager(const QString &hid)=0;
};

#endif // MSFACTORY_H
