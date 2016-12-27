#ifndef BOOKFACTORY_H
#define BOOKFACTORY_H
#include "booktype.h"
#include "mathbook.h"
#include "environmentbook.h"
#include "computerbook.h"
#include "financebook.h"
#include "physicsbook.h"

class BookFactory
{
public:
    BookFactory();
    virtual BookType *createBook(const QString & s);
};

#endif // BOOKFACTORY_H
