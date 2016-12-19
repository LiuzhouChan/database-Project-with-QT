#include "account.h"

account::account(const QString &hid, const QString &hpasswd):
    id(hid),passwd(hpasswd)
{
}

void account::set_id(const QString &s){
    id=s;
}

void account::set_passwd(const QString &s){
    passwd=s;
}

QString account::get_id() const{
    return id;
}
QString account::get_passwd()const{
    return passwd;
}
