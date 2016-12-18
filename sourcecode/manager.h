#ifndef MANAGER_H
#define MANAGER_H
#include <QString>
#include <qsqlquery.h>
class manager
{
private:
    QString id;
    QString passwd;
public:
    manager(const QString &hid,const QString &hpasswd);
    void set_id(const QString &s);
    void set_passwd(const QString &s);
    QString get_id() const;
    QString get_passwd()const;

    void save();
};

#endif // MANAGER_H
