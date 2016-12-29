#include "managerstudentfactory.h"


student* ManagerStudentFactory::createStudent(const QString &hid,const QString &hpassword,const QString &hname
                                                      ,const QString &hbirth, const QString &hsex,const int level,
                                                      const QString &hdept
                                                      ,const int hmax_num,const double hdebt)
{
    if(level==1)
    {
        return new student(hid,hpassword,hname,hbirth, hsex,level,hdept,hmax_num,hdebt);
    }
    else if(level==2)
    {
        return new VIPStudent(hid,hpassword,hname,hbirth, hsex,level,hdept,hmax_num,hdebt);
    }
    else if(level==3)
    {
        return new SVIPStudent(hid,hpassword,hname,hbirth, hsex,level,hdept,hmax_num,hdebt);
    }
    else
    {
        return NULL;
    }


}

student* ManagerStudentFactory::createStudent(const QString &hid)
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select level from Reader where Rno=\""+hid+"\"");
    if(query.next())
    {
        int level(query.value(0).toInt());
        if(level==1)
        {
            return new student(hid);
        }
        else if(level==2)
        {
            return new VIPStudent(hid);
        }
        else if(level==3)
        {
            return new SVIPStudent(hid);
        }
        else
        {
            return NULL;
        }
    }
    return NULL;
}

manager* ManagerStudentFactory::createManager(const QString &hid,const QString &hpassword,const QString &hname
                                                      ,const QString &hbirth, const QString &hsex,const int level)
{
    return new manager(hid,hpassword,hname,hbirth, hsex,level);
}

manager* ManagerStudentFactory::createManager(const QString &hid)
{
    return new manager(hid);
}



