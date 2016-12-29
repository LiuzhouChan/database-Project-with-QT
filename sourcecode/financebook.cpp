#include "financebook.h"

FinanceBook::FinanceBook():BookType("finance")
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select Sno from Shelf where Stype=\""+type+"\"");
    if(query.next())
    {
        shelfNumber=query.value(0).toString();
    }
}
QString FinanceBook::getType()
{
    return type;
}

QString FinanceBook::getShelfnumber()
{
    return shelfNumber;
}

void FinanceBook::setShelfnumber(const QString &s)
{
    shelfNumber=s;
}
