#ifndef PATIENT_H
#define PATIENT_H

#include <QString>
#include <QDataStream>
#include <list>
#include <iterator>
#include <QList>
#include <medicalsertificate.h>
#include <medicalrecord.h>

class Patient
{
public:

    using SizeType = int;
    Patient();
    void setLogin(const QString &str);
    void setName(const QString &str);
    void setSurname(const QString &str);
    void setPatronymic(const QString &str);
    void setDateBirth(const QString &str);
    void setHomeAddress(const QString &str);
    void setCipher(const QString &str);
    void setAttendDoctor(const QString &str);
    void setCertificate(MedicalSertificate &cert);
    void setMedicalRecord(MedicalRecord &rec);

    void load(QDataStream &ds);
    void save(QDataStream &ds) const;

    SizeType sizeCertificare() const;
    SizeType sizeMedRecord() const;

    const QString &getLogin() const;
    const QString &getName() const;
    const QString &getSurname() const;
    const QString &getPatronymic() const;
    const QString &getDateBirth() const;
    const QString &getHomeAddress() const;
    const QString &getCipher() const;
    const QString &getAttendDoctor() const;

    const MedicalSertificate getMedCertificate(int index);
    const MedicalRecord getMedicalRecord(int index);

private:
    QString mLogin;
    QString mName;
    QString mSurname;
    QString mPatronymic;
    QString mDateBirth;
    QString mHomeAddress;
    QString mCipher;
    QString mtAttendDoctor;
    std::list<MedicalSertificate> mMedCertificate;
    std::list<MedicalRecord> mMedicalRecord;

};

#endif // PATIENT_H
