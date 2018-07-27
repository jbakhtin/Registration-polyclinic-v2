#ifndef REGISTRATOR_H
#define REGISTRATOR_H

#include <QString>

class Registrator
{
public:
    Registrator();
    void setLogin(const QString &str);
    void setName(const QString &str);
    void setSurname(const QString &str);
    void setPatronymic(const QString &str);

    void load(QDataStream &ds);
    void save(QDataStream &ds) const;

    const QString &getLogin() const;
    const QString &getName() const;
    const QString &getSurname() const;
    const QString &getPatronymic() const;

private:
    QString mLogin;
    QString mName;
    QString mSurname;
    QString mPatronymic;
};

#endif // REGISTRATOR_H
