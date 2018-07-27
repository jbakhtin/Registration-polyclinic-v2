#include "medicalsertificate.h"

MedicalSertificate::MedicalSertificate()
{

}

//Метод принмет логин пациента, которому выписывается спрака
void MedicalSertificate::setLogin(const QString &str){
    mLogin = str;
}

//Метод принмет заголовок спраки
void MedicalSertificate::setTitle(const QString &str){
    mTitle = str;
}

//Метод принмет текст к справке
void MedicalSertificate::setText(const QString &str){
    mText = str;
}

//Метод принмет принимает фамилию и иниуиалы автора справки
void MedicalSertificate::setAutor(const QString &str){
    mAutor = str;
}

//Метод принимает поток байтов при считывании с фала
//и распределяет их по соответствуюшим полням
void MedicalSertificate::load(QDataStream &ds){
    ds >> mLogin >> mTitle >> mText >> mAutor;
}

//Метод отдает поток байтов содержащих информацию о спраки
void MedicalSertificate::save(QDataStream &ds) const{
    ds << mLogin << mTitle << mText << mAutor;
}

//Метод возвращает логин пациента, которому принадлежит спрака
const QString &MedicalSertificate::getLogin() const{
    return mLogin;
}

//Метод возвращает заголовок справки
const QString &MedicalSertificate::getTitle() const{
    return mTitle;
}

//Метод возвращает текст справки
const QString &MedicalSertificate::getText() const{
    return mText;
}

//Метод возвращает фамилию и иницциалы автора справки
const QString &MedicalSertificate::getAutor() const{
    return mAutor;
}
