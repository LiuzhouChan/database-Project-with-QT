#include "mathbook.h"

MathBook::MathBook():type("math")
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select Sno from Shelf where Stype=\""+type+"\"");
    if(query.next())
    {
        shelfNumber=query.value(0).toString();
    }
}

virtual QString MathBook::getType()
{
    return type;
}

virtual QString MathBook::getShelfnumber()
{
    return shelfNumber;
}

virtual void MathBook::setShelfnumber(const QString &s)
{
    shelfNumber=s;
}
