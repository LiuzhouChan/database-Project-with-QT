#include "bookfactory.h"

BookFactory::BookFactory()
{

}
BookType* BookFactory::createBook(const QString & s)
{
    if(s=="computer")
    {
        return new ComputerBook();
    }
    else if(s=="finance")
    {
        return new FinanceBook();
    }
    else if(s=="math")
    {
        return new MathBook();
    }
    else if(s=="environment")
    {
        return new EnvironmentBook();
    }
    else if(s=="physics")
    {
        return new PhysicsBook();
    }
    else
    {
        return NULL;
    }
}
