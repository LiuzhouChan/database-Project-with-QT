#ifndef MANAGER_H
#define MANAGER_H
#include <QString>
#include <QSqlQuery>
#include "student.h"
#include "account.h"
#include "book.h"
#include "managerstudentfactory.h"
#include "reader.h"
class manager:public account,public Reader
{
public:
    manager(const QString &hid,const QString &hpassword,const QString &hname
            ,const QString &hbirth, const QString &hsex,const int level);
    manager(const QString&s);
    void save();
    void save_new();
    void addNewReader(const QString &hid, const QString &hpassword, const QString &hname
                      , const QString &hbirth, const QString &hsex, const int hlevel, const QString &hdept
                      , const int hmax_num, const int hdebt);

    void modifyreader(student &s, const QString &hpassword, const QString &hname
                      , const QString &hbirth, const QString &hsex, const QString &hdept
                      , const int hmax_num, const double hdebt, const int level);

    void addNewBook(const QString &pname, const QString &pISBN
                    , const QString &pauther, const QString &stype, const QString &pdate
                    , const QString &pprice, const QString &pbookno,
                    const QString &ppublish, const QString &pstate);

    void modifybook(book &b, const QString &pname, const QString &pISBN
                    , const QString &pauther, const QString &stype, const QString &pdate
                    , const QString &pprice, const QString &pbookno,
                    const QString &ppublish, const QString &pstate);

    virtual int borrowbook(Reader *s,book *b);
    virtual void returnbook(Reader *s,book *b);
    virtual int renewbook(Reader *s,book *b);

    virtual int borrowBook(const account &a, book &b);
    virtual void returnBook(const account &a, book &b);
    virtual int renewBook(const account &a, book &b);


    void deleteBook(const QString &bookno);
    void deletReader(const QString &id);
};

#endif // MANAGER_H
