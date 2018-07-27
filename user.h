#ifndef USER_H
#define USER_H

#include <QString>
#include <QDataStream>

class User
{
public:
    User();
    User(QString Login, QString password);
    void setLogin(const QString &str);
    void setPassword(const QString &str);
    void setStatus(const QString &str);
    void load(QDataStream &ds);
    void save(QDataStream &ds) const;
    const QString getLogin() const;
    const QString getPassword() const;
    const QString getStatus() const;

private:
    QString mLogin;
    QString mPassword;
    QString mStatus;
};

#endif // USER_H
