#include "editwindow.h"
#include "ui_editwindow.h"

EditWindow::EditWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditWindow)
{
    ui->setupUi(this);

    //Устагавливаем иконку окна
    QIcon winIcon("images//edit.svg");
    this->setWindowIcon(winIcon);

    //Устанавливаем отображение окна редактирования пользователя
    ui->tabWidget->setTabText(0, "Безопасность");
    ui->tabWidget->setTabText(1, "Персональное");
    ui->tabWidget_2->setTabText(0, "Безопасность");
    ui->tabWidget_2->setTabText(1, "Персональное");
    ui->tabWidget_4->setTabText(0, "Безопасность");
    ui->tabWidget_4->setTabText(1, "Персональное");
}

EditWindow::~EditWindow()
{
    delete ui;
}

//Метод передает базу данных в обект редактирования пользователя
void EditWindow::us(UserLists *d){
    userlists = d;
}

//Устанавливает обект пациента, с которым будем работать
void EditWindow::setPatient(User *user, Patient *patient){

    //Устанавливаем слой для пациента
    ui->stackedWidget->setCurrentIndex(0);

    //Список докторов в исеющихся в системе
    //ui->comboBox_patient_attendDoctor->addItems(userlists->listDoctor());

    mUser = user;
    mPatient = patient;
}

//Устанавливает обект доктор, с которым будем работать
void EditWindow::setDoctor(User *user, Doctor *doctor){

    //Устанавливаем слой для пациента
    ui->stackedWidget->setCurrentIndex(1);
    ui->comboBox_specialities->addItems(userlists->listSpecialities());

    mUser = user;
    mDoctor = doctor;
}

//Устанавливает обект регистратор, с которым будем работать
void EditWindow::setRegistrator(User *user, Registrator *registrator){

    //Устанавливаем слой для пациента
    ui->stackedWidget->setCurrentIndex(2);
    mUser = user;
    mRegistrator = registrator;
}

//Метод обработки нажатия на кнопку "Создать" для пациента
void EditWindow::on_pushButton_create_patient_clicked()
{
    mUser->setPassword(ui->lineEdit_password_patient->text());
    mUser->setLogin(ui->lineEdit_username_patient->text());

    mUser->setStatus("patient");

    mPatient->setLogin(ui->lineEdit_username_patient->text());
    mPatient->setName(ui->lineEdit_patient_name->text());
    mPatient->setSurname(ui->lineEdit_patient_surname->text());
    mPatient->setPatronymic(ui->lineEdit_patient_patronymic->text());

    QString date = ui->dateEdit->text();


    mPatient->setDateBirth(date);
    mPatient->setHomeAddress(ui->lineEdit_patient_HomeAddress->text());
    mPatient->setCipher(ui->lineEdit_patient_cipher->text());
    mPatient->setAttendDoctor(ui->comboBox_patient_attendDoctor->currentText());

    QDialog::accept();
}

//Метод обработки нажатия на кнопку "Создать" для доктора
void EditWindow::on_pushButton_create_doctor_clicked()
{
    mUser->setPassword(ui->lineEdit_doctor_password->text());
    mUser->setLogin(ui->lineEdit_doctor_username->text());

    mUser->setStatus("doctor");

    mDoctor->setLogin(ui->lineEdit_doctor_username->text());
    mDoctor->setName(ui->lineEdit_doctor_name->text());
    mDoctor->setSurname(ui->lineEdit_doctor_surname->text());
    mDoctor->setPatronymic(ui->lineEdit_doctor_patronymic->text());

    QString date = ui->dateEdit->text();

    mDoctor->setEnrollmentDate(date);
    mDoctor->setSpecialty(ui->comboBox_specialities->currentText());

    QDialog::accept();
}

//Метод обработки нажатия на кнопку "Создать" для регистратора
void EditWindow::on_create_registrator_clicked()
{
    mUser->setPassword(ui->lineEdit_pasword_registrator->text());
    mUser->setLogin(ui->lineEdit_username_registrator->text());

    mUser->setStatus("registrator");

    mRegistrator->setLogin(ui->lineEdit_username_registrator->text());
    mRegistrator->setName(ui->lineEdit_name_registrator->text());
    mRegistrator->setSurname(ui->lineEdit_surname_registrator->text());
    mRegistrator->setPatronymic(ui->lineEdit_patronymic_registrator->text());

    QDialog::accept();
}
