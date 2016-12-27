#include "physicsbook.h"

PhysicsBook::PhysicsBook()
{

}
virtual QString PhysicsBook::getType()
{
    return type;
}

virtual QString PhysicsBook::getShelfnumber()
{
    return shelfNumber;
}

virtual void PhysicsBook::setShelfnumber(const QString &s)
{
    shelfNumber=s;
}
