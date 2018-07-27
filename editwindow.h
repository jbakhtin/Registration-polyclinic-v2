#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QDialog>

#include <user.h>
#include <patient.h>
#include <doctor.h>
#include <userlists.h>
#include <registrator.h>

#include <QCryptographicHash.h>
#include <QMessageBox>
#include <QStringList>
#include <QToolTip>

namespace Ui {
class EditWindow;
}

class EditWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditWindow(QWidget *parent = 0);
    void us(UserLists *d);
    void setPatient(User *user, Patient *patient);
    void setDoctor(User *user, Doctor *doctor);
    void setRegistrator(User *user, Registrator *registrator);

    ~EditWindow();

private slots:

    void on_pushButton_create_patient_clicked();

    void on_pushButton_create_doctor_clicked();

    void on_create_registrator_clicked();

private:
    Ui::EditWindow *ui;
    User *mUser;
    UserLists *userlists;
    Doctor *mDoctor;
    Patient *mPatient;
    Registrator *mRegistrator;
};

#endif // EDITWINDOW_H
