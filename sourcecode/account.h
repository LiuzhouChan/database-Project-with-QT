#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QString>

class account
{
private:
    QString id;
    QString passwd;
    QString name;
    QString birth;
    QString sex;
    int level;
public:
    account();
    account(const QString &hid,const QString &hpasswd,const QString &name,const QString &birth,
            const QString &sex,const int level);

    void set_name(const QString &s);
    void set_birth(const QString &s);
    void set_sex(const QString &s);

    QString get_name()const;
    QString get_birth()const;
    QString get_sex()const;

    void set_id(const QString &s);
    void set_passwd(const QString &s);
    QString get_id() const;
    QString get_passwd()const;

    void set_level(const int s);
    int get_level() const;

    virtual ~account();
};

#endif // ACCOUNT_H
