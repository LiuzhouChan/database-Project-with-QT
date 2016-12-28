#include "managerstudentfactory.h"


virtual student* ManagerStudentFactory::createStudent(const QString &hid,const QString &hpassword,const QString &hname
                                                      ,const QString &hbirth, const QString &hsex,const int level,
                                                      const QString &hdept
                                                      ,const int hmax_num,const double hdebt)
{
    switch (level)
    {
    case 1:
        return new student(hid,hpassword,hname,hbirth, hsex,level,hdept,hmax_num,hdebt);
    case 2:
        return new VIPStudent(hid,hpassword,hname,hbirth, hsex,level,hdept,hmax_num,hdebt);
    case 3:
        return new SVIPStudent(hid,hpassword,hname,hbirth, hsex,level,hdept,hmax_num,hdebt);
    default:
        return NULL;
        break;
    }
}

virtual student* ManagerStudentFactory::createStudent(const QString &hid)
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select level from Reader where Rno=\""+id+"\"");
    if(query.next())
    {
        QString level(query.value(0).toInt());
        switch (level)
        {
        case 1:
            return new student(hid);
        case 2:
            return new VIPStudent(hid);
        case 3:
            return new SVIPStudent(hid);
        default:
            break;
        }
    }
    return NULL;
}

virtual manager* ManagerStudentFactory::createManager(const QString &hid,const QString &hpassword,const QString &hname
                                                      ,const QString &hbirth, const QString &hsex,const int level)
{
    return new manager(hid,hpassword,hname,hbirth, hsex,level);
}

virtual manager* ManagerStudentFactory::createManager(const QString &hid)
{
    return new manager(hid);
}



