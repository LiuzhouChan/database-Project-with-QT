#ifndef BOOK_H
#define BOOK_H
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QDate>

class book
{
private:
    QString name;
    QString ISBN;
    QString auther;
    QString sno;
    QString date;
    QString price;
    QString bookno;
    QString publish;
    QString state;
    QString type;
public:
    book(const QString &pname,const QString &pISBN
         ,const QString &pauther,const QString &psno,const QString &pdate
         ,const QString &pprice,const QString &pbookno,
         const QString &ppublish,const QString &pstate);
    book(const QString &bnoo);
    void set_name(const QString & s);
    void set_isbn(const QString & s);
    void set_auther(const QString & s);
    void set_sno(const QString & s);
    void set_date(const QString & s);
    void set_price(const QString & s);
    void set_bookno(const QString & s);
    void set_publish(const QString & s);
    void set_state(const QString & s);

    QString get_position()const;
    QString get_name()const;
    QString get_isbn()const;
    QString get_auther()const;
    QString get_sno()const;
    QString get_date()const;
    QString get_price()const;
    QString get_bookno()const;
    QString get_publish()const;
    QString get_state()const;
    QString get_type()const;
    QDate lastborrow(QString &brno) const;
    QDate duedate() const;
    void save();
    void save_new();

};

#endif // BOOK_H
