#include "student.h"

student::student(const QString &hid, const QString &hpassword, const QString &hname
                 , const QString &hbirth, const QString &hsex,const int level, const QString &hdept
                 , const int hmax_num, const double hdebt):
    account(hid,hpassword,hname,hbirth,hsex,level),dept(hdept),max_num(hmax_num),debt(hdebt),num(0)
{
}

student::student(const QString & id):
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
        dept=query.value(5).toString();
        max_num=query.value(6).toInt();
        debt=query.value(7).toDouble();
    }

    query.exec("select count(*) from BookForRent where Bposi=\""+get_id()+"\"");
    if(query.next())
    {
        num=query.value(0).toInt();
    }
}


void student::set_dept(const QString &s){
    dept=s;
}

void student::set_debt(const double s){
    debt=s;
}

QString student::get_name()const{
    return name;
}

QString student::get_birth()const{
    return birth;
}

QString student::get_sex()const{
    return sex;
}

QString student::get_dept()const{
    return dept;
}

double student::get_debt()const{
    return debt;
}

void student::set_max(const int s){
    max_num=s;
}

int student::get_max()const{
     return max_num;
}

int student::get_booknum()const
{
    return num;
}
void student::save()const
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("update Reader "
               "set password = \""+get_passwd()+"\", "
               "Rname= \""+get_name()+"\", "
               "Rbirth= \""+get_birth()+"\", "
               "Rsex = "+get_sex()+", "
               "Rdept= \""+dept+"\", "
               "BmaxNum= "+QString::number(max_num)+", "
               "Rdebt= "+QString::number(debt)+" "
               "where Rno = \""+get_id()+"\" ");
}

void student::save_new()const
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("insert into Reader values("
               "\""+get_id()+"\","
               "\""+get_passwd()+"\","
               "\""+get_name()+"\","
               "\""+get_birth()+"\","
               "\""+get_sex()+"\","
               "\""+dept+"\","
               ""+QString::number(max_num)+","
               ""+QString::number(debt)+""
               ")"
                );
}

void student::borrowBook(const account &a, book &b)
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    QDateTime date=QDateTime::currentDateTime();
    brrowRecord brecord(a.get_id(),get_id(),b.get_bookno(),date.toString("yyyy-MM-dd hh:mm:ss"));
    brecord.save();
    query.exec("update BookForRent "
               "set Bposi = \""+get_id()+"\" "
               "where Bno = \""+b.get_bookno()+"\" ");
    ++num;
}

void student::returnBook(const account &a, book &b)
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    QString brno;
    QDateTime lastTime=b.lastborrow(brno);
    int day;
    double rate;
    QDateTime date=QDateTime::currentDateTime();
    ReturnRecord r(a.get_id(),brno,date.toString("yyyy-MM-dd HH:mm:ss"));
    r.save();
    query.exec("update BookForRent "
               "set Bposi = null "
               "where Bno = \""+b.get_bookno()+"\" ");
    query.exec("select * from Fine");
    if(query.next())
    {
        day=query.value(0).toInt();
        rate=query.value(1).toDouble();
    }
    auto days=lastTime.daysTo(date);
    if(days>day)
    {
        debt+=(days-day)*rate;
        query.exec("update Reader "
                   "set Rdebt = "+QString::number(debt)+" "
                   "where Rno = \""+get_id()+"\" ");
    }
    --num;
}

void student::renewBook(const account &a, book &b)
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
}
