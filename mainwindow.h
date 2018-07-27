#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QTableWidgetItem>
#include <QCryptographicHash.h>
#include <QLabel>

#include <mainwindow.h>
#include <editwindow.h>
#include <userlists.h>
#include <user.h>
#include <registrator.h>
#include <specialty.h>
#include <certificatewindow.h>
#include <medicalsertificate.h>
#include <patientcard.h>
#include <medicalrecordwindow.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void mainwindow_show(User *user);
    void us(UserLists *d);

    void customizTable();
    void fillInTable();

    bool userDataiIsSuitable(User &user);
    bool patientDataiIsSuitable(Patient &patient);
    bool certificateDataiIsSuitable(MedicalSertificate &medCert);
    bool doctorDataiIsSuitable(Doctor &doctor);
    bool registratorDataiIsSuitable(Registrator &registrator);

    ~MainWindow();

signals:
    void logOut();

private slots:
    void on_actionLogOut_triggered();
    void on_actionCreate_Patient_triggered();
    void on_actionCreate_Doctor_triggered();
    void on_actionCreate_Registrator_2_triggered();

    void on_pushButton_clicked();
    void on_actionSpecialty_triggered();
    void on_pushButton_medicalCertificate_clicked();
    void show_button();

    void on_actionExit_triggered();
    void on_pushButton_patientCard_clicked();
    void on_action_patientCard_triggered();

    void on_pushButton_medicalRecord_clicked();

    //void showUser();

private:
    Ui::MainWindow *ui;
    UserLists *userlists;
    QString mStatus;
    int mIndex;

    Patient mPatient;
    Doctor mDoctor;
    Registrator mRegistrator;

    QString mActiveUser;

};

#endif // MAINWINDOW_H
