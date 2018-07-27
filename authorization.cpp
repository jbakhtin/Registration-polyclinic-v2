#include "authorization.h"
#include "ui_authorization.h"

Authorization::Authorization(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Authorization)
{
    //Инициализируем обект базы данных
    userlists = new UserLists();
    //Проверяем базу данных на наличие в ней данных
    userlists->isEmpty();
    //Считываем данные из базы данных в динамические списки
    userlists->readFiles();
    //Инициализируем окно главной программы
    mainwindow = new MainWindow();
    ui->setupUi(this);
    //Устанавливаем заголовок окна авторизации
    this->setWindowTitle("Авторизация");

    //настраиваем сигнал выхода из профиля программы в окно авторизации
    connect(mainwindow, &MainWindow::logOut, this, &Authorization::logIn_show);

    //Устагавливаем иконку окна
    QIcon winIcon(".//images//key5.svg");
    this->setWindowIcon(winIcon);
}

Authorization::~Authorization()
{
    delete ui;
}

//Метод вызываемый кнопкой "Войти"
//Обрабатывает логин и пароль введеные пользователем
void Authorization::on_pushButton_login_clicked()
{
    //Создаем обьект "Пользователь"
    User user;

    //Считываем догин
    QString login = ui->lineEdit_username->text();

    //Считываем пароль и хэшируем его md5 функцией
    QCryptographicHash CalculateMD5(QCryptographicHash::Md5);
    QByteArray input;
    input.append(ui->lineEdit_password->text());
    CalculateMD5.addData(input);
    QString password = CalculateMD5.result().toHex();

    //Устанавливаем пароль и логин для пользователя
    user.setLogin(login);
    user.setPassword(password);

    //Передаем объект базы данных в обект гланого окна
    mainwindow->us(userlists);

    //Проверяем наличие считанных данных в базе данных
    if(userlists->isRegistered(&user)){
        hide();
        //Открываем главное окно
        mainwindow->mainwindow_show(&user);
    }
}

//Метод отображающий окно авторизации
void Authorization::logIn_show()
{
    //Сохранить или не сохранить логин, пароль при авторизации
    bool saveMe = ui->checkBox_saveme->checkState();

    if(!saveMe){
        ui->checkBox_saveme->setChecked(false);
        ui->lineEdit_username->clear();
        ui->lineEdit_password->clear();
    }
    show();
}

void Authorization::on_pushButton_reset_clicked()
{
    ui->checkBox_saveme->setChecked(false);
    ui->lineEdit_username->clear();
    ui->lineEdit_password->clear();
}
