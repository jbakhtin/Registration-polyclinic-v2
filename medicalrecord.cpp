#include "medicalrecord.h"

MedicalRecord::MedicalRecord()
{

}


 void MedicalRecord::setLogin(const QString &str){
     mLogin = str;
 }

 void MedicalRecord::setDate(const QString &str){
     mDate = str;
 }

 void MedicalRecord::setTime(const QString &str){
     mTime = str;
 }

 void MedicalRecord::setDoctor(const QString &str){
     mDocror = str;
 }

 void MedicalRecord::load(QDataStream &ds){
     ds >> mLogin >> mDate >> mTime >> mDocror;
 }

 void MedicalRecord::save(QDataStream &ds) const{
      ds << mLogin << mDate << mTime << mDocror;
 }

 const QString &MedicalRecord::getLogin() const{
      return mLogin;
 }

 const QString &MedicalRecord::getDate() const{
     return mDate;
 }

 const QString &MedicalRecord::getTime() const{
      return mTime;
 }

 const QString &MedicalRecord::getDoctor() const{
    return mDocror;
 }
