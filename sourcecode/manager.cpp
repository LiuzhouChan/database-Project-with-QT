#include "manager.h"

manager::manager(QString *hid,QString *hpasswd):
    id(hid),passwd(hpasswd)
{

}
manager::~manager()
{
    delete id;
    delete passwd;
}
