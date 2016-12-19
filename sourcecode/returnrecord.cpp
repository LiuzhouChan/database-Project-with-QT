#include "returnrecord.h"

ReturnRecord::ReturnRecord(const QString &roperno,
                           const QString &rbrno,
                           const QString &rreturn_time):
    operno(roperno),brno(rbrno),return_time(rreturn_time)
{

}

//QString ReturnRecord::get_rrno()const{
//    return rrno;
//}
QString ReturnRecord::get_operno()const{
    return operno;
}
QString ReturnRecord::get_brno()const{
    return brno;
}
QString ReturnRecord::get_return_time()const{
    return return_time;
}

void ReturnRecord::save() const{
    QSqlQuery query(QSqlDatabase::database("myconnection"));
    query.exec("insert into ReturnRecord(operNo,BRno,returnTime) values("
               "\""+operno+"\","
               "\""+brno+"\","
               "\""+return_time+"\","
               ")"
                );
}
