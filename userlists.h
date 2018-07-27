#ifndef USERLISTS_H
#define USERLISTS_H

#include <user.h>
#include <patient.h>
#include <doctor.h>
#include <registrator.h>
#include <medicalsertificate.h>
#include <medicalrecord.h>
#include <medicalrecord.h>

#include <md5.h>
#include <cstddef> // size_t
#include <list>
#include <iterator>
#include <QFile>
#include <QDataStream>
#include <QMessageBox>
#include <QStandardItem>
#include <QVariant>
#include <QCryptographicHash.h>
#include <QStringList>
#include <QModelIndex>


#include <QVariant>
#include <QModelIndex>

class UserLists
{

public:
    using SizeType = int;
    UserLists();
    SizeType size() const;
    bool isRegistered(User *user);
    void readFiles();
    void isEmpty();
    void writeFiles();

    void insertPatient(const User &user, const Patient &patient);
    void insertDoctor(const User &user, const Doctor &doctor);
    void insertRegistrator(const User &user, const Registrator &Registrator);
    void insertCertificate(const MedicalSertificate & medCertificate);

    void setCart(int index, MedicalSertificate &cart);
    void setRec(int index, MedicalRecord &rec);

    SizeType sizePatient() const;
    SizeType sizeRegistrator() const;
    SizeType sizeDoctor() const;
    SizeType sizeCertificare() const;

    Patient getPatient(int index);
    Doctor getDoctor(int index);
    Registrator getRegistrator(int index);
    User getUser(int index);
    MedicalSertificate getCertificate(int index);

    int getIndexUser(User &user);

    void eraseUser(int index, QString status);
    void eraseSpecialtity(int index);

    bool freeLogin(User &user);

    QStringList listDoctor();
    QStringList listSpecialities();
    QStringList listDateTimeRecord(QString date);

    void insertSpeciality(const QString &text);

    friend inline QDataStream & operator << (QDataStream &ds, User &p);
    friend inline QDataStream & operator >> (QDataStream &ds, User &p);
    friend inline QDataStream & operator << (QDataStream &ds, Patient &p);
    friend inline QDataStream & operator >> (QDataStream &ds, Patient &p);
    friend inline QDataStream & operator << (QDataStream &ds, Doctor &p);
    friend inline QDataStream & operator >> (QDataStream &ds, Doctor &p);
    friend inline QDataStream & operator << (QDataStream &ds, Registrator &p);
    friend inline QDataStream & operator >> (QDataStream &ds, Registrator &p);
    friend inline QDataStream & operator << (QDataStream &ds, MedicalSertificate &p);
    friend inline QDataStream & operator >> (QDataStream &ds, MedicalSertificate &p);
    friend inline QDataStream & operator << (QDataStream &ds, MedicalRecord &p);
    friend inline QDataStream & operator >> (QDataStream &ds, MedicalRecord &p);


private:
    std::list<User> mUsers;
    std::list<User>::iterator iterUser;
    std::list<Patient> mPatients;
    std::list<Patient>::iterator iterPatient;
    std::list<Doctor> mDoctors;
    std::list<Doctor>::iterator iterDoctors;
    std::list<Registrator> mRegistrators;
    std::list<Registrator>::iterator iterRegistrators;

    QStringList mSpecialties;
};

inline QDataStream & operator >> (QDataStream &ds, User &p){
    p.load(ds);
    return ds;
}

inline QDataStream & operator << (QDataStream &ds, const User &p){
    p.save(ds);
    return ds;
}

inline QDataStream & operator >> (QDataStream &ds, Patient &p){
    p.load(ds);
    return ds;
}

inline QDataStream & operator << (QDataStream &ds, const Patient &p){
    p.save(ds);
    return ds;
}

inline QDataStream & operator >> (QDataStream &ds, Doctor &p){
    p.load(ds);
    return ds;
}

inline QDataStream & operator << (QDataStream &ds, const Doctor &p){
    p.save(ds);
    return ds;
}

inline QDataStream & operator >> (QDataStream &ds, Registrator &p){
    p.load(ds);
    return ds;
}

inline QDataStream & operator << (QDataStream &ds, const Registrator &p){
    p.save(ds);
    return ds;
}

inline QDataStream & operator << (QDataStream &ds, const MedicalSertificate &p){
    p.save(ds);
    return ds;
}

inline QDataStream & operator >> (QDataStream &ds, MedicalSertificate &p){
    p.load(ds);
    return ds;
}

inline QDataStream & operator << (QDataStream &ds, const MedicalRecord &p){
    p.save(ds);
    return ds;
}

inline QDataStream & operator >> (QDataStream &ds, MedicalRecord &p){
    p.load(ds);
    return ds;
}

#endif // USERLISTS_H
