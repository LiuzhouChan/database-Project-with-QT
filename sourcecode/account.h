#ifndef ACCOUNT_H
#define ACCOUNT_H


class account
{
private:
    QString id;
    QString passwd;
public:
    account(const QString &hid,const QString &hpasswd);
    void set_id(const QString &s);
    void set_passwd(const QString &s);
    QString get_id() const;
    QString get_passwd()const;
};

#endif // ACCOUNT_H
