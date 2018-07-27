#include "certificatewindow.h"
#include "ui_certificatewindow.h"

CertificateWindow::CertificateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CertificateWindow)
{
    ui->setupUi(this);
}

CertificateWindow::~CertificateWindow()
{
    delete ui;
}


void CertificateWindow::setPreferences(Patient *patient, MedicalSertificate *medCert, QString activeUser){
    ui->lineEdit_certificateTitle->setPlaceholderText("Диагноз");
    ui->textEdit_certificateText->setPlaceholderText("Описание болезни");
    ui->label_nameDoctor->setText(activeUser);
    mPatient = patient;
    mMedCertificate = medCert;

    this->setWindowTitle("Выдать справку ");

    QIcon winIcon("images//edit.svg");
    this->setWindowIcon(winIcon);
}

void CertificateWindow::setPreferencesForCard(MedicalSertificate *medCert){
    ui->lineEdit_certificateTitle->setPlaceholderText(medCert->getTitle());
    ui->textEdit_certificateText->setPlaceholderText(medCert->getText());
    ui->label_nameDoctor->setText(medCert->getAutor());
    ui->label_2->setText("Выдал: ");

    ui->lineEdit_certificateTitle->setReadOnly(true);
    ui->textEdit_certificateText->setReadOnly(true);
    ui->pushButton_getCertificate->setVisible(false);

}

void CertificateWindow::on_pushButton_getCertificate_clicked()
{
    mMedCertificate->setLogin(mPatient->getLogin());
    mMedCertificate->setText(ui->textEdit_certificateText->toPlainText());
    mMedCertificate->setTitle(ui->lineEdit_certificateTitle->text());
    mMedCertificate->setAutor(ui->label_nameDoctor->text());
    //mPatient->setCertificate(sert);

    QDialog::accept();
}
