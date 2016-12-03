#include "student.h"

student::student(QString *hid,QString *hpassword,QString *hname
                 ,QString *hbirth, QString *hsex, QString *hdept
                 ,int hmax_number,double hdebt):
    manager(hid,hpassword),name(hname),birth(hbirth),
    sex(hsex),dept(hdept),debt(hdebt),max_number(hmax_number)
{

}
student::~student()
{
    delete name;
    delete birth;
    delete sex;
    delete dept;
}
