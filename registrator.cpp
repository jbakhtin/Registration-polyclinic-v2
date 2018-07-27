#include "registrator.h"

Registrator::Registrator()
{

}

void Registrator::setLogin(const QString &str){
    mLogin = str;
}

void Registrator::setName(const QString &str){
    mName = str;
}

void Registrator::setSurname(const QString &str){
    mSurname = str;
}

void Registrator::setPatronymic(const QString &str){
    mPatronymic = str;
}

void Registrator::load(QDataStream &ds){
    ds >> mLogin >> mName >> mSurname >> mPatronymic;
}

void Registrator::save(QDataStream &ds) const{
     ds << mLogin << mName << mSurname << mPatronymic;
}

const QString &Registrator::getLogin() const{
     return mLogin;
}

const QString &Registrator::getName() const{
    return mName;
}

const QString &Registrator::getSurname() const{
     return mSurname;
}

const QString &Registrator::getPatronymic() const{
   return mPatronymic;
}
