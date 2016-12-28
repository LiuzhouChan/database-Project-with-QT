#ifndef READERFACTORY_H
#define READERFACTORY_H
#include <QString>
#include "student.h"
#include "manager.h"
#include "reader.h"
class ReaderFactory
{
public:
    static Reader* createReader(const QString & s);
};

#endif // READERFACTORY_H
