#include "readerfactory.h"

Reader* ReaderFactory::createReader(MSfactory *mf, const QString &s)
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("select level from Reader where Rno=\""+s+"\"");
    if(query.next())
    {
        if(query.value(0).toString()=="0")
        {
            return mf->createManager(s);
        }
        else
        {
            return mf->createStudent(s);
        }
    }
    return NULL;
}
