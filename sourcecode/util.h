#ifndef UTIL_H
#define UTIL_H
#include <QSqlQuery>
#include <QTableWidget>
#include <QHeaderView>
void rmrow(int i,QTableWidget * table);
int settable(QSqlQuery &query,QTableWidget* table, QStringList &header,int i);
#endif // UTIL_H
