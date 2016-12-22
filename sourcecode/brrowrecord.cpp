#include "brrowrecord.h"

brrowRecord::brrowRecord(const QString &boperno,
                         const QString &brno,const QString &bbno,
                         const QString &bstart_time):
    operno(boperno),rno(brno),bno(bbno),start_time(bstart_time)
{

}

//void brrowRecord::set_brno(const QString & s);
//void brrowRecord::set_operno(const QString & s);
//void brrowRecord::set_rno(const QString & s);
//void brrowRecord::set_bno(const QString & s);
//void brrowRecord::set_start_time(const QString & s);

//QString brrowRecord::get_brno()const{
//    return brno;
//}
QString brrowRecord::get_operno()const{
    return operno;
}
QString brrowRecord::get_rno()const{
    return rno;
}
QString brrowRecord::get_bno()const{
    return bno;
}
QString brrowRecord::get_start_time()const{
    return start_time;
}

void brrowRecord::save() const{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("insert into BorrowRecord(operNo,Rno,Bno,startTime) values("
               "\""+operno+"\","
               "\""+rno+"\","
               "\""+bno+"\","
               "\""+start_time+"\""
               ")"
                );
}
