#ifndef BOOK_H
#define BOOK_H
#include <QString>

class book
{
private:
    QString name;
    QString ISBN;
    QString auther;
    QString type;
    QString date;
    QString price;
    QString bookno;
    QString publish;
    QString state;
public:
    book(QString pname,QString pISBN
         ,QString pauther,QString ptype,QString pdate
         ,QString pprice, QString pbookno,
         QString ppublish,QString pstate);

    void set_name(QString & s);
    void set_isbn(QString & s);
    void set_auther(QString & s);
    void set_type(QString & s);
    void set_date(QString & s);
    void set_price(QString & s);
    void set_bookno(QString & s);
    void set_publish(QString & s);
    void set_state(QString & s);

    QString get_name();
    QString get_isbn();
    QString get_auther();
    QString get_type();
    QString get_date();
    QString get_price();
    QString get_bookno();
    QString get_publish();
    QString get_state();

};

#endif // BOOK_H
