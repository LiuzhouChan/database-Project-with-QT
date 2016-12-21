#include "book.h"
#include <QSqlQuery>

//position is the shelf number, while state is in the table of BookForRent
book::book(const QString &pname,const QString &pISBN
           ,const QString &pauther,const QString &psno, const QString &pdate
           ,const QString &pprice, const QString &pbookno,
           const QString &ppublish,const QString &pstate) :
            name(pname),ISBN(pISBN),auther(pauther),
            sno(psno),date(pdate),price(pprice),bookno(pbookno),
            publish(ppublish),state(pstate),type("")
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select Stype from Shelf where Sno=\""+sno+"\" ");
    if(query.next())
    {
        type = query.value(0).toString();
    }
}

book::book(const QString &bnoo):bookno(bnoo)
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select Book.Bname,Book.ISBN,Book.Bauthor,Book.Sno,"
               "Book.Bdate,Book.Bprice,Book.Bpublisher,"
               "BookForRent.Bposi"
               " from Book,BookForRent where BookForRent.ISBN=Book.ISBN and "
               "BookForRent.Bno=\""+bnoo+"\"");
    if(query.next())
    {
        name=query.value(0).toString();
        ISBN=query.value(1).toString();
        auther=query.value(2).toString();
        sno=query.value(3).toString();
        date=query.value(4).toString();
        price=query.value(5).toString(),
        publish=query.value(6).toString();
        state=query.value(7).toString();
    }
    query.exec("select Stype from Shelf where Sno=\""+sno+"\" ");
    if(query.next())
    {
        type = query.value(0).toString();
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

void book::set_sno(const QString & s)
{
    sno=s;
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

QString book::get_sno()const
{
    return sno;
}

QDateTime book::lastborrow(QString &brno) const
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));

    QDateTime lastTime;
    query.exec("select BRno,startTime from BorrowRecord where "
               "Bno=\""+bookno+"\" order by startTime decrease");
    if(query.next())
    {
        brno=query.value(0).toString();
        lastTime=QDateTime::fromString(query.value(1).toString(),"yyyy-MM-dd HH:mm:ss");
        query.exec("select restartTime from renewrecord where "
                   "BRno="+brno+"");
        if(query.next())
        {
            lastTime=QDateTime::fromString(query.value(0).toString(),"yyyy-MM-dd HH:mm:ss");
        }
    }
    return lastTime;

}

QDateTime book::duedate() const
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    int day;
    query.exec("select maxday from Fine");
    if(query.next())
    {
        day=query.value(0).toInt();
    }
    QString brno;
    return lastborrow(brno).addDays(day);
}

void book::save()
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("update BookForRent "
               "set ISBN = \""+ISBN+"\", "
               "Bposi= \""+state+"\", "
               "where Bno = \" "+bookno+"\" ");

    query.exec("update Book "
               "set Bname = \""+name+"\", "
               "Sno= \""+sno+"\", "
               "Bpublisher= \""+publish+"\", "
               "Bauthor = "+auther+", "
               "Bdate= \""+date+"\", "
               "Bprice= "+price+", "
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
               "\""+sno+"\","
               "\""+publish+"\","
               "\""+auther+"\","
               "\""+date+"\","
               ""+price+","
               ")");
}
