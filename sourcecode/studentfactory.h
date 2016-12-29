#ifndef STUDENTFACTORY_H
#define STUDENTFACTORY_H
#include "student.h"

class StudentFactory
{
public:
    virtual ~StudentFactory();
    static student createStudent();
};

#endif // STUDENTFACTORY_H
