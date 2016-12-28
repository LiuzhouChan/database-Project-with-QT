#include "manager.h"

manager::manager(const QString &hid, const QString &hpassword, const QString &hname,
                 const QString &hbirth, const QString &hsex, const int level):
    account(hid,hpassword,hname,hbirth,hsex,level)
{
}

manager::manager(const QString &s)
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select * from Reader where Rno=\""+id+"\"");

    if(query.next())
    {
        set_id(query.value(0).toString());
        set_passwd(query.value(1).toString());
        set_name(query.value(2).toString());
        set_birth(query.value(3).toString());
        set_sex(query.value(4).toString());
        set_level(query.value(8).toInt());
    }
}

void manager::save(){

    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("update Reader "
               "set password = \""+get_passwd()+"\", "
               "Rname= \""+get_name()+"\", "
               "Rbirth= \""+get_birth()+"\", "
               "Rsex = "+get_sex()+", "
               "where Rno = \""+get_id()+"\" ");
}
void manager::save_new()
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("insert into Reader values("
               "\""+get_id()+"\","
               "\""+get_passwd()+"\","
               "\""+get_name()+"\","
               "\""+get_birth()+"\","
               "\""+get_sex()+"\","
               "\"manager\","
               ""+QString::number(0)+","
               ""+QString::number(0)+","
               ""+QString::number(get_level())+""
               ")"
                );
}

void manager::addNewReader(const QString &hid,const QString &hpassword,const QString &hname
                  ,const QString &hbirth, const QString &hsex,const int hlevel, const QString &hdept
                  ,const int hmax_num,const int hdebt)
{
    ManagerStudentFactory m;
    student *s=m.createStudent(hid,hpassword,hname,hbirth,hsex,hlevel,hdept,hmax_num,hdebt);
    s->save_new();
    delete s;
}

void manager::modifyreader(student &s, const QString &hpassword, const QString &hname
                  , const QString &hbirth, const QString &hsex, const QString &hdept
                  , const int hmax_num, const double hdebt, const int level)
{
    s.set_passwd(hpassword);
    s.set_name(hname);
    s.set_birth(hbirth);
    s.set_sex(hsex);
    s.set_dept(hdept);
    s.set_max(hmax_num);
    s.set_debt(hdebt);
    s.set_level(level);
    s.save();
}

void manager::addNewBook(const QString &pname,const QString &pISBN
                ,const QString &pauther,const QString &stype,const QString &pdate
                ,const QString &pprice,const QString &pbookno,
                const QString &ppublish,const QString &pstate)
{
    book b(pname,pISBN,pauther,stype,pdate,pprice,pbookno,ppublish,pstate);
    b.save_new();
}

void manager::modifybook(book &b,const QString &pname,const QString &pISBN
                ,const QString &pauther,const QString &stype,const QString &pdate
                ,const QString &pprice,const QString &pbookno,
                const QString &ppublish,const QString &pstate)
{
    b.set_name(pname);
    b.set_isbn(pISBN);
    b.set_auther(pauther);
    b.set_type(stype);
    b.set_date(pdate);
    b.set_price(pprice);
    b.set_bookno(pbookno);
    b.set_publish(ppublish);
    b.set_state(pstate);
    b.save();
}

virtual int manager::borrowbook(Reader *s, book *b)
{
    return s->borrowBook(*this,*b);
}

virtual void manager::returnbook(Reader *s, book *b)
{
    s->returnBook(*this,*b);
}

virtual int manager::renewbook(Reader *s, book *b)
{
    return s->renewBook(*this,*b);
}



virtual int manager::borrowBook(const account &a, book &b)
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    QDateTime date=QDateTime::currentDateTime();
    brrowRecord brecord(a.get_id(),get_id(),b.get_bookno(),date.toString("yyyy-MM-dd hh:mm:ss"));
    brecord.save();
    query.exec("update BookForRent "
               "set Bposi = \""+get_id()+"\" "
               "where Bno = \""+b.get_bookno()+"\" ");
    return 0;
}

virtual void manager::returnBook(const account &a, book &b)
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    QString brno;
    b.lastborrow(brno);
    QDateTime date=QDateTime::currentDateTime();
    ReturnRecord r(a.get_id(),brno,date.toString("yyyy-MM-dd HH:mm:ss"));
    r.save();
    query.exec("update BookForRent "
               "set Bposi = null "
               "where Bno = \""+b.get_bookno()+"\" ");
}

virtual int manager::renewBook(const account &a, book &b)
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select BRno from BorrowRecord where "
               "Bno=\""+b.get_bookno()+"\" order by startTime desc");
    QString brno;
    if(query.next())
    {
        brno=query.value(0).toString();
    }
    QDateTime date=QDateTime::currentDateTime();
    RenewRecord r(a.get_id(),brno,date.toString("yyyy-MM-dd HH:mm:ss"));
    r.save();
    return 0;
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
