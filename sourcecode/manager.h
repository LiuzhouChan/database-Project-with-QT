#ifndef MANAGER_H
#define MANAGER_H
#include <QString>
#include <qsqlquery.h>
#include "student.h"
#include "account.h"
class manager:public account
{
public:
    manager(const QString &hid,const QString &hpasswd);

    void save();
    void addNewReader(const QString &hid,const QString &hpassword,const QString &hname
                      ,const QString &hbirth, const QString &hsex, const QString &hdept
                      ,const int hmax_num,const int hdebt);

    void modifyreader(student &s,QString &hpassword,const QString &hname
                      ,const QString &hbirth, const QString &hsex, const QString &hdept
                      ,const int hmax_num,const int hdebt);

    void addNewBook();
    void modifybook();
};

#endif // MANAGER_H
