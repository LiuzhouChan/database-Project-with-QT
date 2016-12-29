#include "mathbook.h"

MathBook::MathBook():BookType("math")
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select Sno from Shelf where Stype=\""+type+"\"");
    if(query.next())
    {
        shelfNumber=query.value(0).toString();
    }
}

QString MathBook::getType()
{
    return type;
}

QString MathBook::getShelfnumber()
{
    return shelfNumber;
}

void MathBook::setShelfnumber(const QString &s)
{
    shelfNumber=s;
}
