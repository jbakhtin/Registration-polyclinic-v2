#include "specialty.h"
#include "ui_specialty.h"

Specialty::Specialty(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Specialty)
{
    ui->setupUi(this);

}

Specialty::~Specialty()
{
    delete ui;
}

void Specialty::show_speciality(){
    ui->tableWidget->setColumnCount(1);

    //Устанавливаем заголовки
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("Специальности")));

    //Настраиваем отображение таблицы
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    // Разрешаем выделение только одного элемента
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    // Разрешаем выделение построчно
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    //Запрещаем редактирование полей
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->lineEdit_specialty->setPlaceholderText("Введите название специальности");

    //Заполняем таблицу
    fillInTable();
    exec();
}

//Принемаем указатель на базу данных
void Specialty::us(UserLists *d){
    userlists = d;
}

//Метод обрабатывает кнопку "Добавить\Удалить специальность"
void Specialty::on_addSoecialty_clicked()
{

    if(ui->lineEdit_specialty->text().isEmpty()){
        QMessageBox::warning(this,"Ошибка",
                             "Введите название специальности",
                             "Ok",
                             QString(),
                             QString(),
                             0);
    }

    userlists->insertSpeciality(ui->lineEdit_specialty->text());

    ui->lineEdit_specialty->clear();

    fillInTable();
}

//Метод заполняет таблицу данными
void Specialty::fillInTable(){

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    QStringList specialties = userlists->listSpecialities();

    for(int i = 0; i < specialties.size(); i++){
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(specialties[i]));
    }

}

//Метод обрабатывает кнопку "Удалить специальность"
void Specialty::on_removeSpecialty_clicked()
{
    QModelIndex index = ui->tableWidget->currentIndex();

    if(index.isValid()){
        userlists->eraseSpecialtity(index.row());
        fillInTable();
    }
}
