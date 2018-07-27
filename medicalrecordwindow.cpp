#include "medicalrecordwindow.h"
#include "ui_medicalrecordwindow.h"

MedicalRecordWindow::MedicalRecordWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MedicalRecordWindow)
{
    ui->setupUi(this);
}

MedicalRecordWindow::~MedicalRecordWindow()
{
    delete ui;
}

void MedicalRecordWindow::us(UserLists *d){
    userlists = d;
}

void MedicalRecordWindow::setPreferences(Doctor *doctor, MedicalRecord *medRec, Patient *patient){
    mDoctor = doctor;
    mPatient = patient;
    mMedicalRecord = medRec;

    ui->stackedWidget->setCurrentIndex(0);

    inicialDoctor = mDoctor->getSurname() + " " + mDoctor->getName()[0] + " " + mDoctor->getPatronymic()[0];
    ui->label_RecordDoctor->setText(inicialDoctor);

    ui->pushButton_record->setEnabled(false);
    ui->pushButton_back->setVisible(false);

    this->setWindowTitle("Запись к врачу ");

    QIcon winIcon("images//edit.svg");
    this->setWindowIcon(winIcon);

}

void MedicalRecordWindow::on_pushButton_record_clicked()
{   
    mMedicalRecord->setLogin(mPatient->getLogin());
    mMedicalRecord->setDate(ui->calendarWidget->selectedDate().toString());

    QModelIndex idIndex = ui->listWidget->currentIndex();

    mMedicalRecord->setTime(idIndex.data().toString());
    mMedicalRecord->setDoctor(inicialDoctor);

    QDialog::accept();
}

void MedicalRecordWindow::on_pushButton_next_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->pushButton_record->setEnabled(true);
    ui->pushButton_next->setVisible(false);
    ui->pushButton_back->setVisible(true);

    QString date = ui->calendarWidget->selectedDate().toString();

    ui->listWidget->addItems(userlists->listDateTimeRecord(date));
}

void MedicalRecordWindow::on_pushButton_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->pushButton_record->setEnabled(false);
    ui->pushButton_next->setVisible(true);
    ui->pushButton_back->setVisible(false);
    ui->listWidget->clear();
}
