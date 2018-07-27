#ifndef CERTIFICATEWINDOW_H
#define CERTIFICATEWINDOW_H

#include <QDialog>

#include <userlists.h>
#include <patient.h>
#include <medicalsertificate.h>

namespace Ui {
class CertificateWindow;
}

class CertificateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CertificateWindow(QWidget *parent = 0);
    void us(UserLists *d);
    void setPreferences(Patient *patient, MedicalSertificate *medCert, QString activeUser);
    void setPreferencesForCard(MedicalSertificate *medCert);

    ~CertificateWindow();

private slots:
    void on_pushButton_getCertificate_clicked();

private:
    Ui::CertificateWindow *ui;
    UserLists *userlists;
    Patient *mPatient;
    MedicalSertificate *mMedCertificate;
};

#endif // CERTIFICATEWINDOW_H
