#include "patient.h"

Patient::Patient()
{

}

 void Patient::setLogin(const QString &str){
     mLogin = str;
 }

 void Patient::setName(const QString &str){
     mName = str;
 }

 void Patient::setSurname(const QString &str){
     mSurname = str;
 }

 void Patient::setPatronymic(const QString &str){
     mPatronymic = str;
 }

 void Patient::setDateBirth(const QString &str){
     mDateBirth = str;
 }

 void Patient::setHomeAddress(const QString &str){
     mHomeAddress = str;
 }

 void Patient::setCipher(const QString &str){
     mCipher = str;
 }

 void Patient::setAttendDoctor(const QString &str){
     mtAttendDoctor = str;
 }

 void Patient::setCertificate(MedicalSertificate &cert){
     mMedCertificate.push_back(cert);

 }

 void Patient::setMedicalRecord(MedicalRecord &rec){
     mMedicalRecord.push_back(rec);

 }

 void Patient::load(QDataStream &ds){
     ds >> mLogin >> mName >> mSurname >> mPatronymic >> mDateBirth >> mHomeAddress >> mCipher >> mtAttendDoctor;
 }

 void Patient::save(QDataStream &ds) const{
      ds << mLogin << mName << mSurname << mPatronymic << mDateBirth << mHomeAddress << mCipher << mtAttendDoctor;
 }

 const QString &Patient::getLogin() const{
      return mLogin;
 }

 const QString &Patient::getName() const{
     return mName;
 }

 const QString &Patient::getSurname() const{
      return mSurname;
 }

 const QString &Patient::getPatronymic() const{
    return mPatronymic;
 }

 const QString &Patient::getDateBirth() const{
      return mDateBirth;
 }

 const QString &Patient::getHomeAddress() const{
      return mHomeAddress;
 }

 const QString &Patient::getCipher() const{
      return mCipher;
 }

 const QString &Patient::getAttendDoctor() const{
      return mtAttendDoctor;
 }

 const MedicalSertificate Patient::getMedCertificate(int index){
     std::list<MedicalSertificate>::iterator i;
     int n = 0;
     for (i = mMedCertificate.begin() ; i!=mMedCertificate.end() ; i++){
         if(index == n) return *i;
         n++;
     }
 }

 const MedicalRecord Patient::getMedicalRecord(int index){
     std::list<MedicalRecord>::iterator i;
     int n = 0;
     for (i = mMedicalRecord.begin() ; i!=mMedicalRecord.end() ; i++){
         if(index == n) return *i;
         n++;
     }
 }

 Patient::SizeType Patient::sizeCertificare() const{
    return mMedCertificate.size();
 }

Patient::SizeType Patient::sizeMedRecord() const{
    return mMedicalRecord.size();
}
