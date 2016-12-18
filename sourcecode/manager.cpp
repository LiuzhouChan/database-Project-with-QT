#include "manager.h"

manager::manager(const QString &hid,const QString &hpasswd):
    id(hid),passwd(hpasswd)
{

}


void manager::set_id(const QString &s){
    id=s;
}

void manager::set_passwd(const QString &s){
    passwd=s;
}

QString manager::get_id() const{
    return id;
}
QString manager::get_passwd()const{
    return passwd;
}

void manager::save(){
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("update Manager set password = \""
                   +passwd+"\" where Mon = \""+
                   id+"\"");
}
