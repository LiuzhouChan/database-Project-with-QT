#ifndef PHYSICSBOOK_H
#define PHYSICSBOOK_H
#include "booktype.h"

class PhysicsBook:public BookType
{
public:
    PhysicsBook();
    virtual QString getType();
    virtual QString getShelfnumber();
    virtual void setShelfnumber(const QString & s);
};

#endif // PHYSICSBOOK_H
