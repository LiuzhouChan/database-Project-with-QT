#include "book.h"

book::book(QString *pname,QString *pISBN
           ,QString *pauther,QString *ptype, QString *pdate
           ,QString *pprice, QString *pbookno,
           QString *ppublish,QString *pstate) :
            name(pname),ISBN(pISBN),auther(pauther),
            type(ptype),date(pdate),price(pprice),bookno(pbookno),
            publish(ppublish),state(pstate)
{

}
book::~book()
{
    delete name;
    delete ISBN;
    delete auther;
    delete type;
    delete date;
    delete price;
    delete bookno;
    delete publish;
    delete state;
}
