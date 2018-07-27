#ifndef PATIENTCARD_H
#define PATIENTCARD_H

#include <QDialog>
#include <patient.h>
#include <userlists.h>

#include <certificatewindow.h>

namespace Ui {
class PatientCard;
}

class PatientCard : public QDialog
{
    Q_OBJECT

public:
    explicit PatientCard(QWidget *parent = 0);
    void setPatient(Patient *patient);
    void us(UserLists *d);

    void customizTable();
    void fillInTableOne();
    void fillInTableTwo();
    ~PatientCard();

private slots:
    void showCertificate();



private:
    Ui::PatientCard *ui;
    UserLists *userlists;
    Patient *mPatient;
};

#endif // PATIENTCARD_H
