#ifndef MANAGERSTUDENTFACTORY_H
#define MANAGERSTUDENTFACTORY_H
#include "msfactory.h"
#include "reader.h"
#include "student.h"
#include "manager.h"
#include "vipstudent.h"
#include "svipstudent.h"
#include <QSqlQuery>
//class manager;
class ManagerStudentFactory:public MSfactory
{
public:
    virtual student* createStudent(const QString &hid,const QString &hpassword,const QString &hname
                                   ,const QString &hbirth, const QString &hsex,const int level, const QString &hdept
                                   ,const int hmax_num,const double hdebt);

    virtual student* createStudent(const QString &hid);

    virtual manager* createManager(const QString &hid,const QString &hpassword,const QString &hname
                                   ,const QString &hbirth, const QString &hsex,const int level);

    virtual manager* createManager(const QString &hid);
};

#endif // MANAGERSTUDENTFACTORY_H
