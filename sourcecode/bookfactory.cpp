#include "bookfactory.h"

BookFactory::BookFactory()
{

}
virtual BookType* BookFactory::createBook(const QString & s)
{
    switch (s) {
    case "Computer":
        return new ComputerBook();
        break;
    case "Finance":
        return new FinanceBook();
        break;
    case "Math":
        return new MathBook();
        break;
    case "Environment":
        return new EnvironmentBook();
        break;
    case "Physics":
        return new PhysicsBook();
        break;
    default:
        break;
    }
}
