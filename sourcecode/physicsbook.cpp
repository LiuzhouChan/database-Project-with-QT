#include "physicsbook.h"

PhysicsBook::PhysicsBook():BookType("physics")
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select Sno from Shelf where Stype=\""+type+"\"");
    if(query.next())
    {
        shelfNumber=query.value(0).toString();
    }
}
QString PhysicsBook::getType()
{
    return type;
}

QString PhysicsBook::getShelfnumber()
{
    return shelfNumber;
}

void PhysicsBook::setShelfnumber(const QString &s)
{
    shelfNumber=s;
}
