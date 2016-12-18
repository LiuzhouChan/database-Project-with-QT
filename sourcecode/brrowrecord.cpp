#include "brrowrecord.h"

brrowRecord::brrowRecord(const QString &bbrno,const QString &boperno,
                         const QString &brno,const QString &bbno,
                         const QString &bstart_time):
    brno(bbrno),operno(boperno),rno(brno),bno(bbno),start_time(bstart_time)
{

}

void brrowRecord::set_brno(const QString & s);
void brrowRecord::set_operno(const QString & s);
void brrowRecord::set_rno(const QString & s);
void brrowRecord::set_bno(const QString & s);
void brrowRecord::set_start_time(const QString & s);

QString brrowRecord::get_brno()const;
QString brrowRecord::get_operno()const;
QString brrowRecord::get_rno()const;
QString brrowRecord::get_bno()const;
QString brrowRecord::get_start_time()const;
