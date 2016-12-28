#include "financebook.h"

FinanceBook::FinanceBook():type("finance")
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select Sno from Shelf where Stype=\""+type+"\"");
    if(query.next())
    {
        shelfNumber=query.value(0).toString();
    }
}
virtual QString FinanceBook::getType()
{
    return type;
}

virtual QString FinanceBook::getShelfnumber()
{
    return shelfNumber;
}

virtual void FinanceBook::setShelfnumber(const QString &s)
{
    shelfNumber=s;
}
