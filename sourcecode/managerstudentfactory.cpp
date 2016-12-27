#include "managerstudentfactory.h"

ManagerStudentFactory::ManagerStudentFactory()
{

}

virtual Reader* ManagerStudentFactory::createStudent()
{
    return new student();
}

virtual Reader* ManagerStudentFactory::createVIPStudent()
{
    return new VIPStudent();
}

virtual Reader* ManagerStudentFactory::createSVIPStudent()
{
    return new SVIPStudent();
}

virtual Reader* ManagerStudentFactory::createManager()
{
    return new manager();
}
