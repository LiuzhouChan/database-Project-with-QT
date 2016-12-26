#ifndef BRROWRECORD_H
#define BRROWRECORD_H

#include <QString>
#include <QSqlQuery>
class brrowRecord
{
private:
    QString operno;
    QString rno;
    QString bno;
    QString start_time;
public:
    brrowRecord(const QString &boperno,
                const QString &brno,const QString &bbno,
                const QString &bstart_time);
//    void set_brno(const QString & s);
//    void set_operno(const QString & s);
//    void set_rno(const QString & s);
//    void set_bno(const QString & s);
//    void set_start_time(const QString & s);


    QString get_operno()const;
    QString get_rno()const;
    QString get_bno()const;
    QString get_start_time()const;

    void save() const;




};

#endif // BRROWRECORD_H
