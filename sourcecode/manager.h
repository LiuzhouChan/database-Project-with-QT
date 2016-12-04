#ifndef MANAGER_H
#define MANAGER_H
#include <QString>

class manager
{
public:
    manager(QString hid,QString hpasswd);
    QString id;
    QString passwd;
};

#endif // MANAGER_H
