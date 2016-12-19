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

void manager::modifyreader(student &s,const QString &hpassword,const QString &hname
                  ,const QString &hbirth, const QString &hsex, const QString &hdept
                  ,const int hmax_num,const double hdebt)
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

void manager::addNewBook(const QString &pname,const QString &pISBN
                ,const QString &pauther,const QString &ptype,const QString &pdate
                ,const QString &pprice,const QString &pbookno,
                const QString &ppublish,const QString &pstate)
{
    book b(pname,pISBN,pauther,ptype,pdate,pprice,pbookno,ppublish,pstate);
    b.save_new();
}

void manager::modifybook(book &b,const QString &pname,const QString &pISBN
                ,const QString &pauther,const QString &ptype,const QString &pdate
                ,const QString &pprice,const QString &pbookno,
                const QString &ppublish,const QString &pstate)
{
    b.set_name(pname);
    b.set_isbn(pISBN);
    b.set_auther(pauther);
    b.set_type(ptype);
    b.set_date(pdate);
    b.set_price(pprice);
    b.set_bookno(pbookno);
    b.set_publish(ppublish);
    b.set_state(pstate);
    b.save();
}

void manager::deleteBook(const QString &ISBN)
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("delete from Book where ISBN=\""+ISBN+"\"");
}
void manager::deletReader(const QString &id)
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("delete from Reader where Rno=\""+id+"\"");
}
