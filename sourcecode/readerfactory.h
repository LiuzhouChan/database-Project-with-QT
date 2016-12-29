#ifndef READERFACTORY_H
#define READERFACTORY_H
#include <QString>
#include "student.h"
#include "manager.h"
#include "reader.h"
#include <QSqlQuery>
#include "msfactory.h"
class ReaderFactory
{
public:
    static Reader* createReader(MSfactory *mf,const QString &s);
};

#endif // READERFACTORY_H
