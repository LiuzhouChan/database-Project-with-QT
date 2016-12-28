#ifndef READER_H
#define READER_H
#include "book.h"
#include "account.h"

class Reader
{
public:
    virtual ~Reader();
    virtual void borrowBook(const account &a, book &b)=0;
    virtual void returnBook(const account &a, book &b)=0;
    virtual void renewBook(const account &a, book &b)=0;
};

#endif // READER_H
