#ifndef READER_H
#define READER_H
#include "book.h"
#include "account.h"
class book;
class Reader
{
public:
    virtual ~Reader();
    virtual int borrowBook(const account &a, book &b)=0;
    virtual void returnBook(const account &a, book &b)=0;
    virtual int renewBook(const account &a, book &b)=0;
};

#endif // READER_H
