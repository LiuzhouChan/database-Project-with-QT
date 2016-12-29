#include "environmentbook.h"

EnvironmentBook::EnvironmentBook():BookType("environment")
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select Sno from Shelf where Stype=\""+type+"\"");
    if(query.next())
    {
        shelfNumber=query.value(0).toString();
    }
}

QString EnvironmentBook::getType()
{
    return type;
}

QString EnvironmentBook::getShelfnumber()
{
    return shelfNumber;
}

void EnvironmentBook::setShelfnumber(const QString &s)
{
    shelfNumber=s;
}
