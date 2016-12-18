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

    void set_name(const QString & s);
    void set_isbn(const QString & s);
    void set_auther(const QString & s);
    void set_type(const QString & s);
    void set_date(const QString & s);
    void set_price(const QString & s);
    void set_bookno(const QString & s);
    void set_publish(const QString & s);
    void set_state(const QString & s);

    QString get_name()const;
    QString get_isbn()const;
    QString get_auther()const;
    QString get_type()const;
    QString get_date()const;
    QString get_price()const;
    QString get_bookno()const;
    QString get_publish()const;
    QString get_state()const;

};

#endif // BOOK_H
