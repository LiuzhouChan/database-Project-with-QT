#include "bookfactory.h"

BookFactory::BookFactory()
{

}
virtual BookType* BookFactory::createBook(const QString & s)
{
    switch (s) {
    case "computer":
        return new ComputerBook();
        break;
    case "finance":
        return new FinanceBook();
        break;
    case "math":
        return new MathBook();
        break;
    case "environment":
        return new EnvironmentBook();
        break;
    case "physics":
        return new PhysicsBook();
        break;
    default:
        break;
    }
}
