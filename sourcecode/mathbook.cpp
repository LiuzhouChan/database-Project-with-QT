#include "mathbook.h"

MathBook::MathBook()
{

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
