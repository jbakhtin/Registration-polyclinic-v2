#ifndef MEDICALRECORD_H
#define MEDICALRECORD_H

#include <QString>

class MedicalRecord
{
public:
    MedicalRecord();

    void setLogin(const QString &str);
    void setDate(const QString &str);
    void setTime(const QString &str);
    void setDoctor(const QString &str);

    void load(QDataStream &ds);
    void save(QDataStream &ds) const;

    const QString &getLogin() const;
    const QString &getDate() const;
    const QString &getTime() const;
    const QString &getDoctor() const;

private:
    QString mLogin;
    QString mDate;
    QString mTime;
    QString mDocror;

};

#endif // MEDICALRECORD_H
