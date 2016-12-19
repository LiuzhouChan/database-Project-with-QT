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
