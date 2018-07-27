#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include "mainwindow.h"
#include "userlists.h"
#include "user.h"

#include <QDialog>
#include <QMessageBox>
#include <QCryptographicHash.h>

namespace Ui {
class Authorization;
}

class Authorization : public QDialog
{
    Q_OBJECT

public:
    explicit Authorization(QWidget *parent = 0);
    ~Authorization();

private slots:
    //Слот обрабатывающий нажатие кнопки авторизауии
    void on_pushButton_login_clicked();
    //Отображает окно авторизации
    void logIn_show();

    void on_pushButton_reset_clicked();

private:
    Ui::Authorization *ui;
    //Обьек главного окна программы
    MainWindow *mainwindow;
    //Объект базы данных
    UserLists *userlists;
};

#endif // AUTHORIZATION_H
