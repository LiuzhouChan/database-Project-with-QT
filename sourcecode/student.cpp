#include "student.h"

student::student(const QString &hid, const QString &hpassword, const QString &hname
                 , const QString &hbirth, const QString &hsex, const QString &hdept
                 , const int hmax_num, const int hdebt):
    manager(hid,hpassword),name(hname),birth(hbirth),
    sex(hsex),dept(hdept),max_num(hmax_num),debt(hdebt)
{

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

void student::set_debt(const int s){
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

int student::get_debt()const{
    return debt;
}

void student::set_max(const int s){
    max_num=s;
}

int student::get_max()const{
     return max_num;
}

void student::save()const{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("update Reader "
               "set password = \""+get_passwd()+"\", "
               "set Rname= \""+name+"\", "
               "set Rbirth= \""+birth+"\", "
               "set Rsex = \""+sex+"\", "
               "set Rdept= \""+dept+"\", "
               "set BmaxNum= \""+QString::number(max_num)+"\", "
               "set isDebt= \""+QString::number(debt)+"\", "
               "where Rno = \" "+get_id()+"\" ");
}

void student::save_new()const{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("insert into Reader values("
               "\""+get_id()+"\","
               "\""+get_passwd()+"\","
               "\""+name+"\","
               "\""+birth+"\","
               "\""+sex+"\","
               "\""+dept+"\","
               "\""+QString::number(max_num)+"\","
               "\""+QString::number(debt)+"\","
               ")"
                );
}
