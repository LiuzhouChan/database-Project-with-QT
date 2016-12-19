#include "account.h"

account::account(const QString &hid, const QString &hpasswd):
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
