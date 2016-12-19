#include "manager.h"

manager::manager(const QString &hid,const QString &hpasswd):
    account(hid,hpasswd)
{

}




void manager::save(){
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("update Manager set password = \""
                   +get_passwd()+"\" where Mon = \""+
                   get_id()+"\"");
}

void manager::addNewReader(const QString &hid,const QString &hpassword,const QString &hname
                  ,const QString &hbirth, const QString &hsex, const QString &hdept
                  ,const int hmax_num,const int hdebt)
{
    student s(hid,hpassword,hname,hbirth,hsex,hdept,hmax_num,hdebt);
    s.save_new();
}

void manager::modifyreader(student &s,QString &hpassword,const QString &hname
                  ,const QString &hbirth, const QString &hsex, const QString &hdept
                  ,const int hmax_num,const int hdebt)
{
    s.set_passwd(hpassword);
    s.set_name(hname);
    s.set_birth(hbirth);
    s.set_sex(hsex);
    s.set_dept(hdept);
    s.set_max(hmax_num);
    s.set_debt(hdebt);
    s.save();
}

void addNewBook()
{

}

void modifybook()
{

}
