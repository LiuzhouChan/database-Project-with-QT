#include "computerbook.h"

ComputerBook::ComputerBook():type("computer")
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select Sno from Shelf where Stype=\""+type+"\"");
    if(query.next())
    {
        shelfNumber=query.value(0).toString();
    }
}

virtual QString ComputerBook::getType()
{
    return type;
}

virtual QString ComputerBook::getShelfnumber()
{
    return shelfNumber;
}

virtual void ComputerBook::setShelfnumber(QString & s)
{
    shelfNumber=s;
}
