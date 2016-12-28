#include "environmentbook.h"

EnvironmentBook::EnvironmentBook():type("environment")
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select Sno from Shelf where Stype=\""+type+"\"");
    if(query.next())
    {
        shelfNumber=query.value(0).toString();
    }
}

virtual QString EnvironmentBook::getType()
{
    return type;
}

virtual QString EnvironmentBook::getShelfnumber()
{
    return shelfNumber;
}

virtual void EnvironmentBook::setShelfnumber(const QString &s)
{
    shelfNumber=s;
}
