#include "userlists.h"

UserLists::UserLists()
{
}

//Метод проверяет наличие пциента в базе данных
bool UserLists::isRegistered(User *user)
{
    for(iterUser = mUsers.begin(); iterUser != mUsers.end(); iterUser++)
    {
        if(iterUser->getLogin() == user->getLogin() && iterUser->getPassword() == user->getPassword()) {
            user->setStatus(iterUser->getStatus());
            return true;
        }
    }
    return false;
}

//Метод считввает данные из базы данных в динамические списки
void UserLists::readFiles()
{
    QFile fileUser("userLists//user.txt");

    if(fileUser.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QDataStream outUser(&fileUser);
        User user;
        while(!outUser.atEnd()){
            outUser >> user;
            mUsers.push_back(user);
        }
    }
    else{
        QMessageBox::information(0, "Warning","fail hello");
    }
    fileUser.close();

    QFile filePatient("userLists//patient.txt");

    if(filePatient.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QDataStream outPatient(&filePatient);
       Patient patient;
        while(!outPatient.atEnd()){
            outPatient >>patient;
            mPatients.push_back(patient);
        }
    }
    else QMessageBox::information(0, "Warning","fail 1");

    filePatient.close();

    QFile fileDoctor("userLists//doctor.txt");

    if(fileDoctor.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QDataStream outDoctor(&fileDoctor);
       Doctor doctor;
        while(!outDoctor.atEnd()){
            outDoctor >> doctor;
            mDoctors.push_back(doctor);
        }
    }
    else QMessageBox::information(0, "Warning","fail 2");

    fileDoctor.close();

    QFile fileRegistrator("userLists//registrator.txt");

    if(fileRegistrator.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       QDataStream outRegistrator(&fileRegistrator);
       Registrator registrator;
        while(!outRegistrator.atEnd()){
            outRegistrator >> registrator;
            mRegistrators.push_back(registrator);
        }
    }
    else QMessageBox::information(0, "Warning","fail 3");

    fileRegistrator.close();

    QFile fileSpecialties("userLists//specialities.txt");

    if(fileSpecialties.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       QDataStream outSpecialties(&fileSpecialties);
       QString specialtiy;
        while(!outSpecialties.atEnd()){
            outSpecialties >> specialtiy;
            mSpecialties.push_back(specialtiy);
        }
    }
    else QMessageBox::information(0, "Warning","fail 4");

    QFile fileCertificatesTest("userLists//certificates.txt");

    if(fileCertificatesTest.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       QDataStream outCertificatesTest(&fileCertificatesTest);
       MedicalSertificate medCertificatesTest;
       int i = 0;
       for ( Patient n : mPatients)
       {
            while(!outCertificatesTest.atEnd()){
                outCertificatesTest >> medCertificatesTest;
                setCart(i, medCertificatesTest);
                i++;
            }

            i = 0;
       }
    }
    else QMessageBox::information(0, "Warning","fail 4");

    fileCertificatesTest.close();

    //-------------------------------------------------------------------------------


    QFile fileMedicalRecord("userLists//medicalRecord.txt");

    if(fileMedicalRecord.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       QDataStream outMedicalRecord(&fileMedicalRecord);
       MedicalRecord medicalRecord;
       int i = 0;
       for ( Patient n : mPatients)
       {
            while(!outMedicalRecord.atEnd()){
                outMedicalRecord >> medicalRecord;
                setRec(i, medicalRecord);
                i++;
            }

            i = 0;
       }
    }
    else QMessageBox::information(0, "Warning","fail 4");

    fileMedicalRecord.close();
}

//Метод проверяет наличие данных в базе данных
void UserLists::isEmpty(){
     QFile file("userLists//user.txt");

     User admin;

     QCryptographicHash CalculateMD5(QCryptographicHash::Md5);
     QByteArray input;
     input.append("admin");
     CalculateMD5.addData(input);

     admin.setPassword(CalculateMD5.result().toHex());
     admin.setLogin("admin");
     admin.setStatus("admin");

     if(file.open(QIODevice::ReadOnly))
     {
         QDataStream out(&file);
         if(!out.atEnd()){
             return;
         }
     }
     else{
         QMessageBox::information(0, "Warning","fail 3");
     }
     file.close();

     if(file.open(QIODevice::WriteOnly))
     {
         QDataStream out(&file);
         out << admin;

     }
     else{
         QMessageBox::information(0, "Warning","fail 3");
     }
     file.close();
    }

//Метод записывает данные из динамических списков в базу данных
void UserLists::writeFiles()
{
    QFile fileUser("userLists//user.txt");
    QDataStream inUser(&fileUser);

    if(fileUser.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        for (const User n : mUsers)
        {
            inUser << n;
        }
    }
    else QMessageBox::information(0, "Warning","fail 2");

    fileUser.close();

    QFile filePatient("userLists//patient.txt");
    QDataStream inPatient(&filePatient);

    if(filePatient.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        for (const Patient n : mPatients)
        {
            inPatient << n;
        }
    }
    else QMessageBox::information(0, "Warning","fail 2");

    filePatient.close();

    QFile fileDoctor("userLists//doctor.txt");
    QDataStream inDoctor(&fileDoctor);

    if(fileDoctor.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        for (const Doctor n : mDoctors)
        {
            inDoctor << n;
        }
    }
    else QMessageBox::information(0, "Warning","fail 2");

    fileDoctor.close();

    QFile fileRegistrator("userLists//registrator.txt");
    QDataStream inRegistrator(&fileRegistrator);

    if(fileRegistrator.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        for (const Registrator n : mRegistrators)
        {
            inRegistrator << n;
        }
    }
    else QMessageBox::information(0, "Warning","fail 2");

    fileRegistrator.close();

    QFile fileSpecialities("userLists//specialities.txt");
    QDataStream inSpecialities(&fileSpecialities);

    if(fileSpecialities.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        for (const QString n : mSpecialties)
        {
            inSpecialities << n;
        }
    }
    else QMessageBox::information(0, "Warning","fail 2");

    fileSpecialities.close();

    QFile fileCertificates("userLists//certificates.txt");
    QDataStream inCertificates(&fileCertificates);

    if(fileCertificates.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        MedicalSertificate rec;
        for (Patient n : mPatients){
            for (int i = 0; i < n.sizeCertificare(); i++){
                rec = n.getMedCertificate(i);
                inCertificates << rec;
            }
        }
    }
    else QMessageBox::information(0, "Warning","fail 2");

    fileCertificates.close();

    //--------------------------------------------------------

    QFile fileMedicalRecord("userLists//medicalRecord.txt");
    QDataStream inMedicalRecord(&fileMedicalRecord);

    if(fileMedicalRecord.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        MedicalRecord cert;
        for (Patient n : mPatients){
            for (int i = 0; i < n.sizeMedRecord(); i++){
                cert = n.getMedicalRecord(i);
                inMedicalRecord << cert;
            }
        }
    }
    else QMessageBox::information(0, "Warning","fail 2");

    fileMedicalRecord.close();

}

//Метод вставляет пациента в список
void UserLists::insertPatient(const User &user, const Patient &patient){
    mUsers.push_back(user);
    mPatients.push_back(patient);
}

//Метод вставляет доктора в список
void UserLists::insertDoctor(const User &user, const Doctor &doctor){
    mUsers.push_back(user);
    mDoctors.push_back(doctor);
}

//Метод вставляет регистратора в список
void UserLists::insertRegistrator(const User &user, const Registrator &registrator){
    mUsers.push_back(user);
    mRegistrators.push_back(registrator);
}

//Метод возвращает размер списка пользователей
UserLists::SizeType UserLists::size() const
{
    return mUsers.size();
}

//Список докторов для отображения при создании пользователя
QStringList UserLists::listDoctor(){
    QStringList listDoctor;
    for (const Doctor n : mDoctors)
    {
        QString Surname = n.getSurname();
        QString Name = n.getName();
        QString Patronymic = n.getPatronymic();
        listDoctor.push_back(Surname + " " + Name[0] + "." + Patronymic[0] + ".");
    }
    return listDoctor;
}

QStringList UserLists::listSpecialities(){
    return mSpecialties;
}

//Метод возвращает размер списка пациентов
UserLists::SizeType UserLists::sizePatient() const{
    return mPatients.size();
}

//Метод возвращает размер списка регистраторов
UserLists::SizeType UserLists::sizeRegistrator() const{
    return mRegistrators.size();
}

//Метод возвращает размер списка докторов
UserLists::SizeType UserLists::sizeDoctor() const{
    return mDoctors.size();
}

//Возвращает обект "Пациент" из списка по индексу
Patient UserLists::getPatient(int index){
    std::list<Patient>::iterator i;
    int n = 0;
    for (i = mPatients.begin() ; i!=mPatients.end() ; i++){
        if(index == n) return *i;
        n++;
    }
}

//Возвращает обект "Регистратор" из списка по индексу
Registrator UserLists::getRegistrator(int index){
    std::list<Registrator>::iterator i;
    int n = 0;
    for (i = mRegistrators.begin() ; i!=mRegistrators.end() ; i++){
        if(index == n) return *i;
        n++;
    }
}

//Возвращает обект "Доктор" из списка по индексу
Doctor UserLists::getDoctor(int index){
    std::list<Doctor>::iterator i;
    int n = 0;
    for (i = mDoctors.begin() ; i!=mDoctors.end() ; i++){
        if(index == n) return *i;
        n++;
    }
}

//Метод удаляет пользавателя по индексу и статусу
void UserLists::eraseUser(int index, QString status){
    if(status == "admin"){
        Registrator registrator = getRegistrator(index);
        User user;
        std::list<User>::iterator i;
        int n = 0;
        for (i = mUsers.begin() ; i!=mUsers.end() ; i++){
            user = *i;
            if(user.getLogin() == registrator.getLogin())break;
            n++;
        }
        mRegistrators.erase(std::next(mRegistrators.begin(), index));
        mUsers.erase(std::next(mUsers.begin(), n));
    }

    if(status == "registrator"){
        if(index < sizeDoctor()){
            Doctor doctor = getDoctor(index);
            User user;
            std::list<User>::iterator i;
            int n = 0;
            for (i = mUsers.begin() ; i!=mUsers.end() ; i++){
                user = *i;
                if(user.getLogin() == doctor.getLogin())break;
                n++;
            }
            mDoctors.erase(std::next(mDoctors.begin(), index));
            mUsers.erase(std::next(mUsers.begin(), n));
        }
        else{
            Patient patient = getPatient(index - sizeDoctor());
            User user;
            std::list<User>::iterator i;
            int n = 0;
            for (i = mUsers.begin() ; i!=mUsers.end() ; i++){
                user = *i;
                if(user.getLogin() == patient.getLogin())break;
                n++;
            }
            mPatients.erase(std::next(mPatients.begin(), index - sizeDoctor()));
            mUsers.erase(std::next(mUsers.begin(), n));
        }
    }
}

//Метод удаляет специальность из списка
void UserLists::eraseSpecialtity(int index){
    mSpecialties.erase(std::next(mSpecialties.begin(), index));
}

//Метод проверяет свободен ли логин
bool UserLists::freeLogin(User &user){
    std::list<User>::iterator i;
    User u;
    for (i = mUsers.begin() ; i!=mUsers.end() ; i++){
        u = *i;
        if(u.getLogin() == user.getLogin()) return false;
    }
    return true;
}

//Метод вставляет специальность в список
void UserLists::insertSpeciality(const QString &text){
    mSpecialties.push_back(text);
}

//Метод возврашает индекс пользователя по статусу
int UserLists::getIndexUser(User &user){
    QString status = user.getStatus();
    int index = 0;

    std::list<User>::iterator i;
    User u;
    for (i = mUsers.begin() ; i!=mUsers.end() ; i++){
        u = *i;
        if(u.getStatus() == user.getStatus())
            index++;
        if(u.getLogin() == user.getLogin())
            break;
    }

    return index - 1;
}

void UserLists::setCart(int index, MedicalSertificate &cart){
    std::list<Patient>::iterator i;
    int n = 0;
    for (i = mPatients.begin() ; i!=mPatients.end() ; i++){
        if(index == n) i->setCertificate(cart);
        n++;
    }
}

void UserLists::setRec(int index, MedicalRecord &rec){
    std::list<Patient>::iterator i;
    int n = 0;
    for (i = mPatients.begin() ; i!=mPatients.end() ; i++){
        if(index == n) i->setMedicalRecord(rec);
        n++;
    }
}

QStringList UserLists::listDateTimeRecord(QString date){
    QStringList listDateTime;
    QString str, str2;

    //разобраться с заполнением даты

    QStringList list1;
    for (Patient n : mPatients){
        for (int k = 0; k < n.sizeMedRecord(); k++){
            QString date2 = n.getMedicalRecord(k).getDate();
            if(date2 == date) list1.push_back(n.getMedicalRecord(k).getTime());
        }
    }

     QStringList list2;
    for(int i = 8; i < 16; i++){
        for(int j = 0; j < 60; j = j + 15){
            if (j == 0) str2 = "0";
            else str2 = "";
            str = QString("%1:%2").arg(i).arg(j) + str2;
            list2.push_back(str);

        }
    }
    bool flag = 0;
    if(list1.size() > 0){
        for(int i = 0; i < list2.size(); i++){
            for(int j = 0; j < list1.size(); j++){
                if(list2[i] == list1[j]){
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                listDateTime.push_back(list2[i]);
            }
            flag = 0;
        }
    }else{
        for(int i = 0; i < list2.size(); i++){
            listDateTime.push_back(list2[i]);
        }
    }

    return listDateTime;
}
