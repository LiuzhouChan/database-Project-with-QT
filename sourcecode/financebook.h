#ifndef FINANCEBOOK_H
#define FINANCEBOOK_H
#include "booktype.h"

class FinanceBook:public BookType
{
public:
    FinanceBook();
    virtual QString getType();
    virtual QString getShelfnumber();
    virtual void setShelfnumber(const QString & s);
};

#endif // FINANCEBOOK_H
