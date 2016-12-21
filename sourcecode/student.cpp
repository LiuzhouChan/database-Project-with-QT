#include "student.h"

student::student(const QString &hid, const QString &hpassword, const QString &hname
                 , const QString &hbirth, const QString &hsex, const QString &hdept
                 , const int hmax_num, const double hdebt):
    account(hid,hpassword),name(hname),birth(hbirth),
    sex(hsex),dept(hdept),max_num(hmax_num),debt(hdebt)
{

}

student::student(const QString & id):account("","")
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select * from Reader where Rno=\""+id+"\"");

    if(query.next())
    {
        set_id(query.value(0).toString());
        set_passwd(query.value(1).toString());
        name=query.value(2).toString();
        birth=query.value(3).toString();
        sex=query.value(4).toString();
        dept=query.value(5).toString();
        max_num=query.value(6).toInt();
        debt=query.value(7).toDouble();
    }
}

void student::set_name(const QString &s){
    name=s;
}

void student::set_birth(const QString &s){
    birth=s;
}

void student::set_sex(const QString &s){
    sex=s;
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

void student::save()const
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("update Reader "
               "set password = \""+get_passwd()+"\", "
               "set Rname= \""+name+"\", "
               "set Rbirth= \""+birth+"\", "
               "set Rsex = "+sex+", "
               "set Rdept= \""+dept+"\", "
               "set BmaxNum= "+QString::number(max_num)+", "
               "set isDebt= "+QString::number(debt)+" "
               "where Rno = \" "+get_id()+"\" ");
}

void student::save_new()const
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("insert into Reader values("
               "\""+get_id()+"\","
               "\""+get_passwd()+"\","
               "\""+name+"\","
               "\""+birth+"\","
               "\""+sex+"\","
               "\""+dept+"\","
               ""+QString::number(max_num)+","
               ""+QString::number(debt)+""
               ")"
                );
}

void student::borrowBook(const account &a, book &b)
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    QDate date=QDate::currentDate();
    brrowRecord brecord(a.get_id(),get_id(),b.get_bookno(),date.toString());
    brecord.save();
    query.exec("update BookForRent "
               "set Bposi = \""+get_id()+"\" "
               "where Bno = \" "+b.get_bookno()+"\" ");

}

void student::returnBook(const account &a, book &b)
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    QString brno;
    QDate lastTime=b.lastborrow(brno);
    int day;
    double rate;
    double fine;
    QDate date=QDate::currentDate();
    ReturnRecord r(a.get_id(),brno,date.toString());
    r.save();
    query.exec("update BookForRent "
               "set Bposi = \"null\", "
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
        fine=(days-day)*rate;
        query.exec("update Reader "
                   "set Rdebt = Rdebt+"+QString::number(fine)+""
                   "where Rno = \""+get_id()+"\" ");
    }
}

void student::renewBook(const account &a, book &b)
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select BRno from BorrowRecord where "
               "Bno=\""+b.get_bookno()+"\" order by startTime decrease");
    QString brno;
    if(query.next())
    {
        brno=query.value(0).toString();
    }
    QDate date=QDate::currentDate();
    RenewRecord r(a.get_id(),brno,date.toString());
    r.save();
}
