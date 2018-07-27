#include "patientcard.h"
#include "ui_patientcard.h"

PatientCard::PatientCard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientCard)
{
    ui->setupUi(this);
    connect(ui->tableWidget_medCertificate, SIGNAL(activated(QModelIndex)),this, SLOT(showCertificate()));
}

PatientCard::~PatientCard()
{
    delete ui;
}

void PatientCard::setPatient(Patient *patient){
    mPatient = patient;
    ui->label_name->setText(patient->getName());
    ui->label_surname->setText(patient->getSurname());
    ui->label_patronymic->setText(patient->getPatronymic());
    ui->label_dateBirth->setText(patient->getDateBirth());
    ui->label_homeAddress->setText(patient->getHomeAddress());
    ui->label_cipher->setText(patient->getCipher());

    this->setWindowTitle("Карта пациента ");

    QIcon winIcon("images//edit.svg");
    this->setWindowIcon(winIcon);

    customizTable();
}

void PatientCard::us(UserLists *d){
    userlists = d;
}

void PatientCard::customizTable(){
    //!Настраиваем таблицу справок
    ui->tableWidget_medCertificate->setColumnCount(2);
    ui->tableWidget_medRecord->setColumnCount(3);

    //Устанавливаем заголовки для первой талицы
    ui->tableWidget_medCertificate->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("Диагноз")));
    ui->tableWidget_medCertificate->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("Выдал")));

    //Устанавливаем заголовки для второй талицы
    ui->tableWidget_medRecord->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("Дата")));
    ui->tableWidget_medRecord->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("Время")));
    ui->tableWidget_medRecord->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("Врач")));

    //!Общие настройки таблицы
    //Настраиваем отображение первой таблицы
    ui->tableWidget_medCertificate->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget_medCertificate->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->tableWidget_medCertificate->setColumnWidth(1, 175);

    //Настраиваем отображение второй таблицы
    ui->tableWidget_medRecord->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget_medRecord->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->tableWidget_medRecord->setColumnWidth(1, 100);

    // Разрешаем выделение только одного элемента
    ui->tableWidget_medCertificate->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_medRecord->setSelectionMode(QAbstractItemView::SingleSelection);

    // Разрешаем выделение построчно
    ui->tableWidget_medCertificate->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_medRecord->setSelectionBehavior(QAbstractItemView::SelectRows);


    //Запрещаем редактирование полей
    ui->tableWidget_medCertificate->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_medRecord->setEditTriggers(QAbstractItemView::NoEditTriggers);


    fillInTableOne();
    fillInTableTwo();
}

void PatientCard::fillInTableOne(){

    ui->tableWidget_medCertificate->clearContents();
    ui->tableWidget_medCertificate->setRowCount(0);

    MedicalSertificate certificate;
    for(int i = 0; i < mPatient->sizeCertificare(); i++){
        certificate = mPatient->getMedCertificate(i);
        if (certificate.getLogin() == mPatient->getLogin()){
            ui->tableWidget_medCertificate->insertRow(i);
            ui->tableWidget_medCertificate->setItem(i, 0, new QTableWidgetItem(certificate.getTitle()));
            ui->tableWidget_medCertificate->setItem(i, 1, new QTableWidgetItem(certificate.getAutor()));
        }
    }
}

void PatientCard::fillInTableTwo(){

    ui->tableWidget_medRecord->clearContents();
    ui->tableWidget_medRecord->setRowCount(0);

    MedicalRecord rec;
    for(int i = 0; i < mPatient->sizeMedRecord(); i++){
        rec = mPatient->getMedicalRecord(i);
        if (rec.getLogin() == mPatient->getLogin()){
            ui->tableWidget_medRecord->insertRow(i);
            ui->tableWidget_medRecord->setItem(i, 0, new QTableWidgetItem(rec.getDate()));
            ui->tableWidget_medRecord->setItem(i, 1, new QTableWidgetItem(rec.getTime()));
            ui->tableWidget_medRecord->setItem(i, 2, new QTableWidgetItem(rec.getDoctor()));
        }
    }
}

void PatientCard::showCertificate(){
  QModelIndex idIndex = ui->tableWidget_medCertificate->currentIndex();

  MedicalSertificate certificate;
  for(int i = 0; i < mPatient->sizeCertificare(); i++){
      certificate = mPatient->getMedCertificate(i);
      if (idIndex.row() == i){
          break;
      }
  }

  CertificateWindow dialog;
  dialog.setPreferencesForCard(&certificate);
  dialog.exec();
}
