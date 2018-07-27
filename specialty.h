#ifndef SPECIALTY_H
#define SPECIALTY_H

#include <userlists.h>

#include <QDialog>
#include <QMessageBox>


namespace Ui {
class Specialty;
}

class Specialty : public QDialog
{
    Q_OBJECT

public:
    explicit Specialty(QWidget *parent = 0);
    void us(UserLists *d);
    void fillInTable();
    void show_speciality();

    ~Specialty();
private slots:
    void on_addSoecialty_clicked();

    void on_removeSpecialty_clicked();

private:
    Ui::Specialty *ui;

    UserLists *userlists;
};

#endif // SPECIALTY_H
