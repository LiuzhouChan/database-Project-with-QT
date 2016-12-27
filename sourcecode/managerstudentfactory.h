#ifndef MANAGERSTUDENTFACTORY_H
#define MANAGERSTUDENTFACTORY_H
#include "reader.h"
#include "student.h"
#include "vipstudent.h"
#include "svipstudent.h"
#include "manager.h"

class ManagerStudentFactory
{
public:
    ManagerStudentFactory();
    virtual Reader* createStudent();
    virtual Reader* createVIPStudent();
    virtual Reader* createSVIPStudent();
    virtual Reader* createManager();
};

#endif // MANAGERSTUDENTFACTORY_H
