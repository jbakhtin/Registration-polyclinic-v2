#include "user.h"

User::User()
{
}

void User::load(QDataStream &ds){
    ds >> mLogin >> mPassword >> mStatus;
}

void User::save(QDataStream &ds) const{
    ds << mLogin << mPassword << mStatus;
}

void User::setPassword(const QString &str)
{
    mPassword = str;
}

void User::setLogin(const QString &str)
{
    mLogin = str;
}

void User::setStatus(const QString &str)
{
    mStatus = str;
}

const QString User::getPassword() const
{
    return mPassword;
}

const QString User::getLogin() const
{
    return mLogin;
}

const QString User::getStatus() const
{
    return mStatus;
}
