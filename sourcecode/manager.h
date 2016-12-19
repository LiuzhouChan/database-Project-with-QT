#ifndef MANAGER_H
#define MANAGER_H
#include <QString>
#include <qsqlquery.h>
#include "student.h"
#include "account.h"
#include "book.h"
class manager:public account
{
public:
    manager(const QString &hid,const QString &hpasswd);

    void save();
    void addNewReader(const QString &hid,const QString &hpassword,const QString &hname
                      ,const QString &hbirth, const QString &hsex, const QString &hdept
                      ,const int hmax_num,const int hdebt);

    void modifyreader(student &s, const QString &hpassword, const QString &hname
                      , const QString &hbirth, const QString &hsex, const QString &hdept
                      , const int hmax_num, const double hdebt);

    void addNewBook(const QString &pname,const QString &pISBN
                    ,const QString &pauther,const QString &ptype,const QString &pdate
                    ,const QString &pprice,const QString &pbookno,
                    const QString &ppublish,const QString &pstate);

    void modifybook(book &b,const QString &pname,const QString &pISBN
                    ,const QString &pauther,const QString &ptype,const QString &pdate
                    ,const QString &pprice,const QString &pbookno,
                    const QString &ppublish,const QString &pstate);

    void deleteBook(const QString &bookno);
    void deletReader(const QString &id);
};

#endif // MANAGER_H
