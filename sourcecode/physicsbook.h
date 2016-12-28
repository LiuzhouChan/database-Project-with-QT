#ifndef PHYSICSBOOK_H
#define PHYSICSBOOK_H
#include "booktype.h"
#include <QSqlQuery>
#include <QTableWidget>
#include <QHeaderView>
#include <QString>
class PhysicsBook:public BookType
{
public:
    PhysicsBook();
    virtual QString getType();
    virtual QString getShelfnumber();
    virtual void setShelfnumber(const QString & s);
};

#endif // PHYSICSBOOK_H
