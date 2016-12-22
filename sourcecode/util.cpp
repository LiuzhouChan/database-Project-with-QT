#include "util.h"


int settable(QSqlQuery &query,QTableWidget* table, QStringList &header,int i)
{
    int size(header.size());
    table->setColumnCount(size);
    table->setHorizontalHeaderLabels(header);
    table->horizontalHeader()->setStretchLastSection(true);
    while(query.next())
    {
        if(table->rowCount()<i+1)
        {
            table->insertRow(i);
        }
        for(int j=0;j<size;++j)
        {
            table->setItem(i,j,
                   new QTableWidgetItem(query.value(j).toString()));
        }
         ++i;
    }
    return i;

}

void rmrow(int i,QTableWidget * table)
{
    int num=table->rowCount();
    for(int jj=0;jj<num-i;++jj)
    {
        table->removeRow(i);
    }
}

QDateTime ulastborrow(QString &brno,const QString &bookno)
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));

    QDateTime lastTime;
    query.exec("select BRno,startTime from BorrowRecord where "
               "Bno=\""+bookno+"\" order by startTime desc");
    if(query.next())
    {
        brno=query.value(0).toString();
        lastTime=query.value(1).toDateTime();
        query.exec("select restartTime from renewrecord where "
                   "BRno="+brno+"");
        if(query.next())
        {
            auto llastTime=query.value(0).toDateTime();
            if(llastTime.isValid())
            {
                lastTime=llastTime;
            }
        }
    }
    return lastTime;

}

int umaxday()
{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    int day;
    query.exec("select maxday from Fine");
    if(query.next())
    {
        day=query.value(0).toInt();
    }
    return day;
}

