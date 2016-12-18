#include "student.h"

student::student(const QString &hid, const QString &hpassword, const QString &hname
                 , const QString &hbirth, const QString &hsex, const QString &hdept
                 , const int hdebt):
    manager(hid,hpassword),name(hname),birth(hbirth),
    sex(hsex),dept(hdept),debt(hdebt)
{

}



void set_name(const QString &s){
    name=s;
}

void set_birth(const QString &s){
    birth=s;
}

void set_sex(const QString &s){
    sex=s;
}

void set_dept(const QString &s){
    dept=s;
}

void set_debt(const int s){
    debt=s;
}

QString student::get_name(){
    return name;
}

QString student::get_birth(){
    return birth;
}

QString student::get_sex(){
    return sex;
}

QString student::get_dept(){
    return dept;
}

int student::get_debt(){
    return debt;
}

void student::save(){
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("update Manager set password = \""
               +passwd+"\" where Mon = \""+
               id+"\"")
}

void student::save_new(){

}
