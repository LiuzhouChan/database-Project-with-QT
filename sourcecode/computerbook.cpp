#include "computerbook.h"

ComputerBook::ComputerBook()
{

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
