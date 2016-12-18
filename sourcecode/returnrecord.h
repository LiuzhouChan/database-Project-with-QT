#ifndef RETURNRECORD_H
#define RETURNRECORD_H

#include <QString>
#include <QSqlQuery>

class ReturnRecord
{
private:
    QString rrno;
    QString operno;
    QString brno;
    QString return_time;
public:
    ReturnRecord(const QString &rrrno,
    const QString &roperno,
    const QString &rbrno,
    const QString &rreturn_time);

    QString get_rrno()const;
    QString get_operno()const;
    QString get_brno()const;
    QString get_return_time()const;

    void save() const;

};

#endif // RETURNRECORD_H
