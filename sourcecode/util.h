#ifndef UTIL_H
#define UTIL_H
#include <QSqlQuery>
#include <QTableWidget>
#include <QHeaderView>
#include <QDate>
#include <QString>
void rmrow(int i,QTableWidget * table);
int settable(QSqlQuery &query,QTableWidget* table, QStringList &header,int i);
int umaxday();
QDateTime ulastborrow(QString &brno,const QString &bookno);
#endif // UTIL_H
