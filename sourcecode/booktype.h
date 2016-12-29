#ifndef BOOKTYPE_H
#define BOOKTYPE_H
#include <QString>

class BookType
{
protected:
    QString type;
    QString shelfNumber;
public:
    BookType(const QString &type);
    virtual ~BookType();
    virtual QString getType()=0;
    virtual QString getShelfnumber()=0;
    virtual void setShelfnumber(const QString & s)=0;
};

#endif // BOOKTYPE_H
