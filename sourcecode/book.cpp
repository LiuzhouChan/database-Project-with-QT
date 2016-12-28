#include "book.h"
#include <QSqlQuery>

//position is the shelf number, while state is in the table of BookForRent
book::book(const QString &pname, const QString &pISBN
           , const QString &pauther, const QString &stype, const QString &pdate
           , const QString &pprice, const QString &pbookno,
           const QString &ppublish, const QString &pstate) :
            name(pname),ISBN(pISBN),auther(pauther),
            date(pdate),price(pprice),bookno(pbookno),
            publish(ppublish),state(pstate)
{
    BookFactory b;
    type=b.createBook(stype);
}

book::book(const QString &bnoo):bookno(bnoo)
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select Book.Bname,Book.ISBN,Book.Bauthor,Shelf.Stype,"
               "Book.Bdate,Book.Bprice,Book.Bpublisher,"
               "BookForRent.Bposi"
               " from Book,BookForRent,Shelf where BookForRent.ISBN=Book.ISBN and "
               "BookForRent.Bno=\""+bnoo+"\"and Shelf.Sno=Book.Sno");
    if(query.next())
    {

        name=query.value(0).toString();
        ISBN=query.value(1).toString();
        auther=query.value(2).toString();
        BookFactory b;
        type=b.createBook(query.value(3).toString());
        date=query.value(4).toString();
        price=query.value(5).toString(),
        publish=query.value(6).toString();
        state=query.value(7).toString();
        if(state.isEmpty())
        {
            state="NULL";
        }
    }

}

void book::set_type(const QString &s)
{
    delete type;
    BookFactory b;
    type=b.createBook(stype);
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
    return type->getType();
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
    return type->getShelfnumber();
}

QDateTime book::lastborrow(QString &brno) const
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));

    QDateTime lastTime;
    query.exec("select BRno,startTime from BorrowRecord where "
               "Bno=\""+bookno+"\" order by startTime desc");
    if(query.next())
    {
        brno=query.value(0).toString();
        lastTime=query.value(1).toDateTime();
        query.exec("select restartTime from renewrecord where "
                   "BRno="+brno+" order by restartTime desc");
        if(query.next())
        {
            auto llastime=query.value(0).toDateTime();
            if(llastime.isValid())
            {
                lastTime=llastime;
            }
        }
    }
    return lastTime;

}
//after finish the student class
QDateTime book::duedate(account &ss) const
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    int day;
    query.exec("select Bposi from BookForRent where Bno=\""+bookno+"\""); //sss
    if(query.next())
    {
        day=query.value(0).toInt()*ss;
    }
    QString brno;
    return lastborrow(brno).addDays(day*account.get_level());
}

void book::save()
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("update Book "
               "set Bname = \""+name+"\", "
               "Sno= \""+type->getShelfnumber()+"\", "
               "Bpublisher= \""+publish+"\", "
               "Bauthor = \""+auther+"\", "
               "Bdate= \""+date+"\", "
               "Bprice= "+price+" "
               "where ISBN = \""+ISBN+"\" ");

    if(state=="NULL")
    {
        query.exec("update BookForRent "
                   "Bposi= "+state+" "
                   "where Bno = \""+bookno+"\" ");
    }
    else
    {
        query.exec("update BookForRent "
                   "Bposi= \""+state+"\" "
                   "where Bno = \""+bookno+"\" ");
    }
}

void book::save_new()
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));

    query.exec("insert into Book values("
               "\""+ISBN+"\","
               "\""+name+"\","
               "\""+type->getShelfnumber()+"\","
               "\""+publish+"\","
               "\""+auther+"\","
               "\""+date+"\","
               ""+price+""
               ")");

    query.exec("insert into BookForRent values("
               "\""+bookno+"\","
               "\""+ISBN+"\","
               "NULL"
               ")");
}
