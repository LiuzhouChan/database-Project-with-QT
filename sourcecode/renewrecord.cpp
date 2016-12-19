#include "renewrecord.h"

RenewRecord::RenewRecord(const QString &roperno,
                         const QString &rbrno,
                         const QString &rrestart_time):
    operno(roperno),brno(rbrno),restart_time(rrestart_time)
{

}


//QString RenewRecord::get_nrno()const{
//    return nrno;
//}
QString RenewRecord::get_operno()const{
    return operno;
}
QString RenewRecord::get_brno()const{
    return brno;
}
QString RenewRecord::get_restart_time()const{
    return restart_time;
}

void RenewRecord::save() const{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("insert into renewrecord(operNo,BRno,restartTime) values("
               "\""+operno+"\","
               "\""+brno+"\","
               "\""+restart_time+"\","
               ")"
                );
}
