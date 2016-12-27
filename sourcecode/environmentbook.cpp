#include "environmentbook.h"

EnvironmentBook::EnvironmentBook()
{

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
