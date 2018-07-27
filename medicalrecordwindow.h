#ifndef MEDICALRECORDWINDOW_H
#define MEDICALRECORDWINDOW_H

#include <QDialog>
#include <doctor.h>
#include <patient.h>
#include <QString>
#include <medicalrecord.h>
#include <userlists.h>

namespace Ui {
class MedicalRecordWindow;
}

class MedicalRecordWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MedicalRecordWindow(QWidget *parent = 0);
    ~MedicalRecordWindow();

    void setPreferences(Doctor *doctor, MedicalRecord *medRec, Patient *patient);
    void us(UserLists *d);

private slots:
    void on_pushButton_record_clicked();

    void on_pushButton_next_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::MedicalRecordWindow *ui;

    UserLists *userlists;
    Doctor *mDoctor;
    QString inicialDoctor;
    Patient *mPatient;
    MedicalRecord *mMedicalRecord;
};

#endif // MEDICALRECORDWINDOW_H
