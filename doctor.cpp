#include "doctor.h"

Doctor::Doctor()
{

}

void Doctor::setLogin(const QString &str){
    mLogin = str;
}

void Doctor::setName(const QString &str){
    mName = str;
}

void Doctor::setSurname(const QString &str){
    mSurname = str;
}

void Doctor::setPatronymic(const QString &str){
    mPatronymic = str;
}

void Doctor::setEnrollmentDate(const QString &str){
    mEnrollmentDate = str;
}

void Doctor::setSpecialty(const QString &str){
    mSpecialty = str;
}

void Doctor::load(QDataStream &ds){
    ds >> mLogin >> mName >> mSurname >> mPatronymic >> mEnrollmentDate >> mSpecialty;
}

void Doctor::save(QDataStream &ds) const{
    ds << mLogin << mName << mSurname << mPatronymic << mEnrollmentDate << mSpecialty;
}

const QString &Doctor::getLogin() const{
    return mLogin;
}

const QString &Doctor::getName() const{
    return mName;
}

const QString &Doctor::getSurname() const{
    return mSurname;
}

const QString &Doctor::getPatronymic() const{
    return mPatronymic;
}

const QString &Doctor::getEnrollmentDate() const{
    return mEnrollmentDate;
}

const QString &Doctor::getSpecialty() const{
    return mSpecialty;
}
