#include "physicsbook.h"

PhysicsBook::PhysicsBook():type("physics")
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select Sno from Shelf where Stype=\""+type+"\"");
    if(query.next())
    {
        shelfNumber=query.value(0).toString();
    }
}
virtual QString PhysicsBook::getType()
{
    return type;
}

virtual QString PhysicsBook::getShelfnumber()
{
    return shelfNumber;
}

virtual void PhysicsBook::setShelfnumber(const QString &s)
{
    shelfNumber=s;
}
