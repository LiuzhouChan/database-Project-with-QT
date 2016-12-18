#ifndef BRROWRECORD_H
#define BRROWRECORD_H

#include <QString>

class brrowRecord
{
private:
    QString brno;
    QString operno;
    QString rno;
    QString bno;
    QString start_time;
public:
    brrowRecord(const QString &bbrno,const QString &boperno,
                const QString &brno,const QString &bbno,
                const QString &bstart_time);
    void set_brno(const QString & s);
    void set_operno(const QString & s);
    void set_rno(const QString & s);
    void set_bno(const QString & s);
    void set_start_time(const QString & s);

    QString get_brno()const;
    QString get_operno()const;
    QString get_rno()const;
    QString get_bno()const;
    QString get_start_time()const;

};

#endif // BRROWRECORD_H
