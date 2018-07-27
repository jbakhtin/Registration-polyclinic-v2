#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
       ui->setupUi(this);
       connect(ui->tableWidget, SIGNAL(clicked(QModelIndex)), this, SLOT(show_button()));
       //connect(ui->tableWidget, SIGNAL(activated(QModelIndex)),this, SLOT(showCertificate()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Метод отображает главное окно
void MainWindow::mainwindow_show(User *user){
    //Считываем статус пользователя
    mStatus = user->getStatus();

    mIndex = userlists->getIndexUser(*user);
    if(mStatus == "patient"){
        mPatient = userlists->getPatient(mIndex);
        mActiveUser = mPatient.getSurname() + " " + mPatient.getName()[0] + ". " + mPatient.getPatronymic()[0] + "." + " [Пациент]";
    }
    else if(mStatus == "doctor"){
        mDoctor = userlists->getDoctor(mIndex);
        mActiveUser = mDoctor.getSurname() + " " + mDoctor.getName()[0] + ". " + mDoctor.getPatronymic()[0] + "." + " [Доктор]";
    }
    else if(mStatus == "registrator"){
        mRegistrator = userlists->getRegistrator(mIndex);
        mActiveUser = mRegistrator.getSurname() + " " + mRegistrator.getName()[0] + ". " + mRegistrator.getPatronymic()[0] + "." + " [Регистратор]";
    }
    else mActiveUser = " [Администратор]";

    //Выставляем начальный функционал главного окна
    ui->actionCreate_Registrator_2->setVisible(true);
    ui->actionCreate_Doctor->setVisible(true);
    ui->actionCreate_Patient->setVisible(true);
    ui->menuFile->actions()[0]->setVisible(true);
    ui->menuFile->actions()[1]->setVisible(true);
    ui->menuFile->actions()[2]->setVisible(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton->setVisible(true);
    ui->pushButton_medicalCertificate->setVisible(false);
    ui->pushButton_patientCard->setVisible(false);
    ui->pushButton_medicalRecord->setVisible(false);

    //Ограничиваем функционал окна в соответствии со статусом пользователя
    if(mStatus == "patient" || mStatus == "doctor"){
        ui->menuFile->actions()[0]->setVisible(false);
        ui->menuFile->actions()[1]->setVisible(false);
        ui->pushButton->setVisible(false);
        if(mStatus == "patient"){
            ui->menuFile->actions()[2]->setVisible(true);
            ui->pushButton_medicalRecord->setVisible(true);
            ui->pushButton_medicalRecord->setEnabled(false);
        }
        if(mStatus == "doctor"){
            ui->pushButton_medicalCertificate->setVisible(true);
            ui->pushButton_medicalCertificate->setEnabled(false);
            ui->pushButton_patientCard->setVisible(true);
            ui->pushButton_patientCard->setEnabled(false);
        }
    }else{
        if(mStatus == "admin"){
            ui->actionCreate_Doctor->setVisible(false);
            ui->actionCreate_Patient->setVisible(false);
        }else if(mStatus == "registrator"){
            ui->actionCreate_Registrator_2->setVisible(false);
            ui->menuFile->actions()[1]->setVisible(false);
        }
    }

    //Настраиваем таблицу пользователей
    customizTable();

    //Устанавливаем заголовок окна
    this->setWindowTitle("Регистратура поликлиники. ");

    //Сообщаем, в строке состаяния, информацию о пользователе вощедщем в систему
    ui->statusBar->showMessage("Вы вошли под пользователем : " + mActiveUser);

    //Устагавливаем иконку окна
    QIcon winIcon("images//users2.svg");
    this->setWindowIcon(winIcon);

    //Отображаем главное окно
    show();
}

//Метод производит настройку таблицы главного окна
void MainWindow::customizTable(){

    //!производим настройку в соответствии со статусом пользователя ноходящемся в системе
    if(mStatus == "admin"){
        //Задаем кол-во столбцов и устанавливаем заголовок
        ui->tableWidget->setColumnCount(3);

        //Устанавливаем заголовки
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("Фамилия")));
        ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("Имя")));
        ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("Отчество")));
    }
    else if(mStatus == "doctor"){
        //Задаем кол-во столбцов и устанавливаем заголовок
        ui->tableWidget->setColumnCount(4);

        //Устанавливаем заголовки
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("Фамилия")));
        ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("Имя")));
        ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("Отчество")));
        ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem(tr("Дата рождения")));
    }
    else if(mStatus == "patient"){
        //Задаем кол-во столбцов и устанавливаем заголовок
        ui->tableWidget->setColumnCount(4);

        //Устанавливаем заголовки
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("Фамилия")));
        ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("Имя")));
        ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("Отчество")));
        ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem(tr("Специальность")));
    }
    else if(mStatus == "registrator"){
        //Задаем кол-во столбцов и устанавливаем заголовок
        ui->tableWidget->setColumnCount(4);

        //Устанавливаем заголовки
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("Фамилия")));
        ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("Имя")));
        ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("Отчество")));
        ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem(tr("Статус")));
    }

    //!Общие настройки таблицы
    //Настраиваем отображение таблицы
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->tableWidget->setColumnWidth(1, 100);

    // Разрешаем выделение только одного элемента
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    // Разрешаем выделение построчно
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    //Запрещаем редактирование полей
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //Заполняем таблицу
    fillInTable();
}

void MainWindow::fillInTable(){

    //Заполняем таблицу в соответствии со статусом пользователя ноходящемся в системе
    if(mStatus == "admin"){
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);

        Registrator registrator;
        for(int i = 0; i < userlists->sizeRegistrator(); i++){
            registrator = userlists->getRegistrator(i);
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(registrator.getSurname()));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(registrator.getName()));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(registrator.getPatronymic()));
        }
    }
    else if(mStatus == "doctor"){
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);

        Patient patient;
        for(int i = 0; i < userlists->sizePatient(); i++){
            patient = userlists->getPatient(i);
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(patient.getSurname()));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(patient.getName()));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(patient.getPatronymic()));
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem(patient.getDateBirth()));
        }
    }
    else if(mStatus == "patient"){
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);

        Doctor doctor;
        for(int i = 0; i < userlists->sizeDoctor(); i++){
            doctor = userlists->getDoctor(i);
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(doctor.getSurname()));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(doctor.getName()));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(doctor.getPatronymic()));
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem(doctor.getSpecialty()));
        }
    }
    else if(mStatus == "registrator"){
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);

        Doctor doctor;
        for(int i = 0; i < userlists->sizeDoctor(); i++){
            doctor = userlists->getDoctor(i);
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(doctor.getSurname()));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(doctor.getName()));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(doctor.getPatronymic()));
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem("Доктор"));
        }
        Patient patient;
        for(int i = 0; i < userlists->sizePatient(); i++){
            patient = userlists->getPatient(i);
            int index = userlists->sizeDoctor() + i;
            ui->tableWidget->insertRow(index);
            ui->tableWidget->setItem(index, 0, new QTableWidgetItem(patient.getSurname()));
            ui->tableWidget->setItem(index, 1, new QTableWidgetItem(patient.getName()));
            ui->tableWidget->setItem(index, 2, new QTableWidgetItem(patient.getPatronymic()));
            ui->tableWidget->setItem(index, 3, new QTableWidgetItem("Пациент"));
        }
    }
}

//Метод обрабатывает кнопку "Выйти из профиля"
void MainWindow::on_actionLogOut_triggered(){
    //Записываем в файл информцию из динамических списков
    userlists->writeFiles();
    this->close();
    emit logOut();
}

void MainWindow::on_actionExit_triggered()
{
    //Записываем в файл информцию из динамических списков
    userlists->writeFiles();
    this->close();
}

//Метод принимает уазатель на обект базы данных
void MainWindow::us(UserLists *d){
    userlists = d;
}

//Метод орабатывает кнопку "Создать пациента" в меню "Управление"
void MainWindow::on_actionCreate_Patient_triggered()
{
    User user;
    Patient patient;
    EditWindow editDialog(this);

    editDialog.us(userlists);
    editDialog.setPatient(&user, &patient);

    editDialog.setWindowTitle("Пациент");

    while(1){
        if ( editDialog.exec() != EditWindow::Accepted)
        {
            return;
        }
        if(userDataiIsSuitable(user) && patientDataiIsSuitable(patient)) break;
    }

    QCryptographicHash CalculateMD5(QCryptographicHash::Md5);
    QByteArray input;
    input.append(user.getPassword());
    CalculateMD5.addData(input);
    user.setPassword(CalculateMD5.result().toHex());

    userlists->insertPatient(user, patient);
    fillInTable();
}

//Метод орабатывает кнопку "Создать доктора" в меню "Управление"
void MainWindow::on_actionCreate_Doctor_triggered()
{
    User user;
    Doctor doctor;
    EditWindow editDialog(this);

    editDialog.us(userlists);
    editDialog.setDoctor(&user, &doctor);

    editDialog.setWindowTitle("Доктор");

    while(1){
        if ( editDialog.exec() != EditWindow::Accepted)
        {
            return;
        }
        if(userDataiIsSuitable(user)) break;
    }

    QCryptographicHash CalculateMD5(QCryptographicHash::Md5);
    QByteArray input;
    input.append(user.getPassword());
    CalculateMD5.addData(input);
    user.setPassword(CalculateMD5.result().toHex());

    userlists->insertDoctor(user, doctor);
    fillInTable();
}

//Метод орабатывает кнопку "Создать регистратора" в меню "Управление"
void MainWindow::on_actionCreate_Registrator_2_triggered()
{
    User user;
    Registrator registrator;
    EditWindow editDialog(this);

    editDialog.setRegistrator(&user, &registrator);
    editDialog.setWindowTitle("Регистратор");

    while(1){
        if ( editDialog.exec() != EditWindow::Accepted)
        {
            return;
        }
        if(userDataiIsSuitable(user) && registratorDataiIsSuitable(registrator)) break;
    }

    QCryptographicHash CalculateMD5(QCryptographicHash::Md5);
    QByteArray input;
    input.append(user.getPassword());
    CalculateMD5.addData(input);
    user.setPassword(CalculateMD5.result().toHex());

    userlists->insertRegistrator(user, registrator);
    fillInTable();
}


//Метод обрабатывает кнопку "Удалить"
void MainWindow::on_pushButton_clicked()
{
    QModelIndex index = ui->tableWidget->currentIndex();

    if(index.isValid()){
        userlists->eraseUser(index.row(), mStatus);
        fillInTable();
    }
}
bool MainWindow::patientDataiIsSuitable(Patient &patient){
    if(patient.getName() == NULL){
        QMessageBox::warning(this,"Ошибка",
                             "Введите имя пользователя",
                             "Ok",
                             QString(),
                             QString(),
                             0);
        return false;
    }
    if(patient.getSurname() == NULL){
        QMessageBox::warning(this,"Ошибка",
                             "Введите фамлию пользователя",
                             "Ok",
                             QString(),
                             QString(),
                             0);
        return false;
    }
    if(patient.getPatronymic() == NULL){
        QMessageBox::warning(this,"Ошибка",
                             "Введите очество пользователя",
                             "Ok",
                             QString(),
                             QString(),
                             0);
        return false;
    }
    return true;
}

bool MainWindow::registratorDataiIsSuitable(Registrator &registrator){
    if(registrator.getName() == NULL){
        QMessageBox::warning(this,"Ошибка",
                             "Введите имя пользователя",
                             "Ok",
                             QString(),
                             QString(),
                             0);
        return false;
    }
    if(registrator.getSurname() == NULL){
        QMessageBox::warning(this,"Ошибка",
                             "Введите фамлию пользователя",
                             "Ok",
                             QString(),
                             QString(),
                             0);
        return false;
    }
    if(registrator.getPatronymic() == NULL){
        QMessageBox::warning(this,"Ошибка",
                             "Введите очество пользователя",
                             "Ok",
                             QString(),
                             QString(),
                             0);
        return false;
    }
    return true;
}

bool MainWindow::doctorDataiIsSuitable(Doctor &doctor){
    if(doctor.getName() == NULL){
        QMessageBox::warning(this,"Ошибка",
                             "Введите имя пользователя",
                             "Ok",
                             QString(),
                             QString(),
                             0);
        return false;
    }
    if(doctor.getSurname() == NULL){
        QMessageBox::warning(this,"Ошибка",
                             "Введите фамлию пользователя",
                             "Ok",
                             QString(),
                             QString(),
                             0);
        return false;
    }
    if(doctor.getPatronymic() == NULL){
        QMessageBox::warning(this,"Ошибка",
                             "Введите очество пользователя",
                             "Ok",
                             QString(),
                             QString(),
                             0);
        return false;
    }
    return true;
}

bool MainWindow::userDataiIsSuitable(User &user){

    if(user.getLogin() == NULL){
        QMessageBox::warning(this,"Ошибка",
                             "Логин не введен",
                             "Ok",
                             QString(),
                             QString(),
                             0);
        return false;
    }

    if(user.getLogin().length() < 2){
        QMessageBox::warning(this,"Ошибка",
                             "Логин слишком короткий",
                             "Ok",
                             QString(),
                             QString(),
                             0);
        return false;
    }

    if(user.getPassword() == NULL){
        QMessageBox::warning(this,"Ошибка",
                             "Пароль не введен",
                             "Ok",
                             QString(),
                             QString(),
                             0);
        return false;
    }

    if(user.getPassword().length() < 2){
        QMessageBox::warning(this,"Ошибка",
                             "Пароль слишком короткий",
                             "Ok",
                             QString(),
                             QString(),
                             0);
        return false;
    }


    bool freeLogin = userlists->freeLogin(user);
    if(!freeLogin){
        QMessageBox::warning(this,"Ошибка",
                             "Пользователь с таким логином уже зарегистрирован",
                             "Ok",
                             QString(),
                             QString(),
                             0);
        return false;
    }

    return true;
}

//Метод обрабатывает нажатие по кнопке "Добавить\Удалить специальность"
void MainWindow::on_actionSpecialty_triggered()
{
    Specialty specialtyDialog(this);
    specialtyDialog.us(userlists);

    specialtyDialog.setWindowTitle("Добавить\Удалить специальность");

    specialtyDialog.show_speciality();
}

//Метод обрабатывает нажатие по кнопке "Выдать справку"
void MainWindow::on_pushButton_medicalCertificate_clicked()
{
    QModelIndex index = ui->tableWidget->currentIndex();

    Patient patient;
    if(index.row() >= 0){
        patient = userlists->getPatient(index.row());

        MedicalSertificate medCert;
        CertificateWindow certificateDialog;
        certificateDialog.setPreferences(&patient, &medCert, mActiveUser);

        while(1){
            if ( certificateDialog.exec() != EditWindow::Accepted)
            {
                return;
            }
             if(certificateDataiIsSuitable(medCert)) break;
        }
        userlists->setCart(index.row(), medCert);
    }
}

bool MainWindow::certificateDataiIsSuitable(MedicalSertificate &medCert){

    if(medCert.getTitle() == NULL){
        QMessageBox::warning(this,"Ошибка",
                             "Введите диагноз",
                             "Ok",
                             QString(),
                             QString(),
                             0);
        return false;
    }
    if(medCert.getText() == NULL){
        QMessageBox::warning(this,"Ошибка",
                             "Заполните описание",
                             "Ok",
                             QString(),
                             QString(),
                             0);
        return false;
    }
    return true;

}

//Метод делает кнопки доступными по условию
void MainWindow::show_button(){
    ui->pushButton_medicalCertificate->setEnabled(true);
    ui->pushButton->setEnabled(true);
    ui->pushButton_patientCard->setEnabled(true);
    ui->pushButton_medicalRecord->setEnabled(true);
}

 void MainWindow::on_pushButton_patientCard_clicked()
 {
    QModelIndex index = ui->tableWidget->currentIndex();
    PatientCard patientCardDialig;
    Patient patient;

    if(index.row() >= 0){
        patient = userlists->getPatient(index.row());
        patientCardDialig.us(userlists);
        patientCardDialig.setPatient(&patient);
        patientCardDialig.exec();
    }
 }

 void MainWindow::on_action_patientCard_triggered()
 {
     PatientCard patientCardDialig;
     mPatient = userlists->getPatient(mIndex);
     patientCardDialig.us(userlists);
     patientCardDialig.setPatient(&mPatient);

     patientCardDialig.exec();

 }

 void MainWindow::on_pushButton_medicalRecord_clicked()
 {
     QModelIndex index = ui->tableWidget->currentIndex();

     Doctor doctor;
     if(index.row() >= 0){
         doctor = userlists->getDoctor(index.row());

         MedicalRecord medRec;
         MedicalRecordWindow medicalRecordDialog;
         medicalRecordDialog.us(userlists);
         medicalRecordDialog.setPreferences(&doctor, &medRec, &mPatient);

         while(1){
             if ( medicalRecordDialog.exec() != EditWindow::Accepted)
             {
                 return;
             }
             else break;
         }
         userlists->setRec(index.row(), medRec);
     }
 }
