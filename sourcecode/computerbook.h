#ifndef COMPUTERBOOK_H
#define COMPUTERBOOK_H
#include "booktype.h"

class ComputerBook:public BookType
{
public:
    ComputerBook();
    virtual QString getType();
    virtual QString getShelfnumber();
    virtual void setShelfnumber(const QString & s);
};

#endif // COMPUTERBOOK_H
