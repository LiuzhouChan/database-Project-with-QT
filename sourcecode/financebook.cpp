#include "financebook.h"

FinanceBook::FinanceBook()
{

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
