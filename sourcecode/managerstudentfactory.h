#ifndef MANAGERSTUDENTFACTORY_H
#define MANAGERSTUDENTFACTORY_H
#include "student.h"
#include "vipstudent.h"
#include "svipstudent.h"
#include "manager.h"
#include "reader.h"
class ManagerStudentFactory
{
public:
    ManagerStudentFactory();
    virtual Reader* createReader();
};

#endif // MANAGERSTUDENTFACTORY_H
