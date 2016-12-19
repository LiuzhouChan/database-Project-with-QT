#include "book.h"
#include <QSqlQuery>
book::book(const QString &pname,const QString &pISBN
           ,const QString &pauther,const QString &ptype, const QString &pdate
           ,const QString &pprice, const QString &pbookno,
           const QString &ppublish,const QString &pstate) :
            name(pname),ISBN(pISBN),auther(pauther),
            type(ptype),date(pdate),price(pprice),bookno(pbookno),
            publish(ppublish),state(pstate),position("")
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select Sno from Shelf where Stype=\""+type+"\" ");
    if(query.next())
    {
        position = query.value(0).toString();
    }
}

void book::set_name(const QString & s)
{
    name=s;
}

void book::set_isbn(const QString & s)
{
    ISBN=s;
}

void book::set_auther(const QString & s)
{
    auther=s;
}

void book::set_type(const QString & s)
{
    type=s;
}

void book::set_date(const QString & s)
{
    date=s;
}

void book::set_price(const QString & s)
{
    price =s;
}

void book::set_bookno(const QString & s)
{
    bookno=s;
}

void book::set_publish(const QString & s)
{
    publish=s;
}

void book::set_state(const QString & s)
{
    state=s;
}

QString book::get_name()const
{
    return name;
}

QString book::get_isbn()const
{
    return ISBN;
}

QString book::get_auther()const
{
    return auther;
}

QString book::get_type()const
{
    return type;
}

QString book::get_date()const
{
    return date;
}

QString book::get_price()const
{
    return price;
}
QString book::get_bookno()const
{
    return bookno;
}
QString book::get_publish()const
{
    return publish;
}
QString book::get_state()const
{
    return state;
}

QString book::get_position()const
{
    return position;
}

void book::save()
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("update BookForRent "
               "set ISBN = \""+ISBN+"\", "
               "set Bposi= \""+state+"\", "
               "where Bno = \" "+bookno+"\" ");

    query.exec("update Book "
               "set Bname = \""+name+"\", "
               "set Sno= \""+position+"\", "
               "set Bpublisher= \""+publish+"\", "
               "set Bauthor = "+auther+", "
               "set Bdate= \""+date+"\", "
               "set Bprice= \""+date+"\", "
               "where ISBN = \" "+ISBN+"\" ");
}

void book::save_new()
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("insert into BookForRent values("
               "\""+bookno+"\","
               "\""+ISBN+"\","
               "NULL"
               ")");

    query.exec("insert into Book values("
               "\""+ISBN+"\","
               "\""+name+"\","
               "\""+state+"\","
               "\""+publish+"\","
               "\""+auther+"\","
               "\""+date+"\","
               ""+price+","
               ")");
}
