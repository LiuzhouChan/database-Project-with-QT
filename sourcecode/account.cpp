#include "account.h"

account::account(const QString &hid, const QString &hpasswd, const QString &name, const QString &birth, const QString &sex, const int level):
    id(hid),passwd(hpasswd),name(name),birth(birth),sex(sex),level(level)
{
}
account::account()
{
}

void account::set_id(const QString &s)
{
    id=s;
}

void account::set_passwd(const QString &s)
{
    passwd=s;
}

QString account::get_id() const
{
    return id;
}

QString account::get_passwd()const
{
    return passwd;
}

void account::set_name(const QString &s)
{
    name=s;
}

void account::set_birth(const QString &s)
{
    birth=s;
}

void account::set_sex(const QString &s)
{
    sex=s;
}
void account::set_level(const int s)
{
    level=s;
}

int account::get_level() const
{
    return level;
}

account::~account()
{

}
