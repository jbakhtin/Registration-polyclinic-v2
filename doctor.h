#ifndef DOCTOR_H
#define DOCTOR_H

#include <QString>

class Doctor
{
public:
    Doctor();

    //Устанавливает
    void setLogin(const QString &str);
    void setName(const QString &str);
    void setSurname(const QString &str);
    void setPatronymic(const QString &str);
    void setEnrollmentDate(const QString &str);
    void setSpecialty(const QString &str);

    void load(QDataStream &ds);
    void save(QDataStream &ds) const;

    const QString &getLogin() const;
    const QString &getName() const;
    const QString &getSurname() const;
    const QString &getPatronymic() const;
    const QString &getEnrollmentDate() const;
    const QString &getSpecialty() const;

private:
    QString mLogin;
    QString mName;
    QString mSurname;
    QString mPatronymic;
    QString mEnrollmentDate;
    QString mSpecialty;
};

#endif // DOCTOR_H
