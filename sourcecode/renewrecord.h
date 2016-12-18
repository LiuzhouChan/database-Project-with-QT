#ifndef RENEWRECORD_H
#define RENEWRECORD_H

#include <QString>
#include <QSqlQuery>

class RenewRecord
{
private:
    QString nrno;
    QString operno;
    QString brno;
    QString restart_time;
public:
    RenewRecord(const QString &rrrno,
    const QString &roperno,
    const QString &rbrno,
    const QString &rrestart_time);

    QString get_nrno()const;
    QString get_operno()const;
    QString get_brno()const;
    QString get_restart_time()const;

    void save() const;
};

#endif // RENEWRECORD_H
