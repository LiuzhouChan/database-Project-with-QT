#ifndef MATHBOOK_H
#define MATHBOOK_H
#include "booktype.h"
#include <QSqlQuery>
#include <QTableWidget>
#include <QHeaderView>
#include <QString>
class MathBook:public BookType
{
public:
    MathBook();
    virtual QString getType();
    virtual QString getShelfnumber();
    virtual void setShelfnumber(const QString & s);
};

#endif // MATHBOOK_H
