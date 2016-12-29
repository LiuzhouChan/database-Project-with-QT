#include "readerfactory.h"

static Reader* ReaderFactory::createReader(const QString & s)
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select level from Reader where Rno=\""+s+"\"");
    if(query.next())
    {
        ManagerStudentFactory mf;
        if(query.value(0).toString()="0")
        {
            return mf.createManager(s);
        }
        else
        {
            return mf.createStudent(s);
        }
    }
    return NULL;
}
