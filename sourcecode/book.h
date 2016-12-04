#ifndef BOOK_H
#define BOOK_H
#include <QString>

class book
{
public:
    book(QString pname,QString pISBN
         ,QString pauther,QString ptype,QString pdate
         ,QString pprice, QString pbookno,
         QString ppublish,QString pstate);
    QString name;
    QString ISBN;
    QString auther;
    QString type;
    QString date;
    QString price;
    QString bookno;
    QString publish;
    QString state;
};

#endif // BOOK_H
