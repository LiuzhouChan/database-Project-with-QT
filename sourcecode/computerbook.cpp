#include "computerbook.h"

ComputerBook::ComputerBook():BookType("computer")
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select Sno from Shelf where Stype=\""+type+"\"");
    if(query.next())
    {
        shelfNumber=query.value(0).toString();
    }
}

QString ComputerBook::getType()
{
    return type;
}

QString ComputerBook::getShelfnumber()
{
    return shelfNumber;
}

void ComputerBook::setShelfnumber(const QString & s)
{
    shelfNumber=s;
}
