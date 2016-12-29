#ifndef ENVIRONMENTBOOK_H
#define ENVIRONMENTBOOK_H
#include "booktype.h"
#include <QSqlQuery>
#include <QTableWidget>
#include <QHeaderView>
#include <QString>

class EnvironmentBook:public BookType
{
public:
    EnvironmentBook();
    virtual QString getType();
    virtual QString getShelfnumber();
    virtual void setShelfnumber(const QString & s);
};

#endif // ENVIRONMENTBOOK_H
