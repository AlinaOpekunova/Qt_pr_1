#include "ninthtask.h"
#include "ui_ninthtask.h"
#include "QFileDialog"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <QString>

using namespace std;

NinthTask::NinthTask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NinthTask)
{
    ui->setupUi(this);
}

NinthTask::~NinthTask()
{
    delete ui;
}

struct Book
{
    string name;
    string author;
    string publisher;
    unsigned int year;
};

vector<Book> database;

void NinthTask::on_readFile_clicked()
{
    int nBooks; // число записей о книгах
    QString out; // для вывода в textEdit

    ifstream document("library.txt"); // открываем файл для чтения

    if (!document)
        ui->outTextEdit->setText("File open error!");
    else {
        document >> nBooks; // в начале файле указано количество книг, считываем его
        ui->nBooks->setText(QString::number(nBooks));
        for(int i=0;i<nBooks;i++){
            database.push_back(Book()); // добавляем в вектор структур новую
            getline(document, database[i].name, ','); // и записываем данные, перечисленные через запятую
            document.ignore();
            getline(document, database[i].author, ',');
            document.ignore();
            getline(document, database[i].publisher, ',');
            document.ignore();
            document >> database[i].year;
            // далее записываем данные для вывода в textEdit
            out.append(QString::number(i+1)+QString::fromStdString(") "+database[i].name+", "
                                                                 +database[i].author+", "
                                                                 +database[i].publisher+", ")
                       +QString::number(database[i].year)+"\n");
        }
        document.close(); // после чтения закрываем файл
    };
    ui->outTextEdit->setText(out); // выводим прочитанные данные
};


void NinthTask::on_dateSearch_clicked()
{
    QString outDate = ""; // для вывода в textEdit
    unsigned int date = ui->inLineEdit->text().toInt(); // получаем год из inLineEdit
    for(std::vector<Book>::iterator i = database.begin(); i<database.end();i++)
    { // проходимся по всему вектору и выводим только то, что соответствует условию
        if(i->year == date)
            outDate.append(QString::fromStdString(i->name+", "+i->author+", "
                                                  +i->publisher+", ")+QString::number(i->year)+"\n");
    };
    ui->outTextEdit->setText(outDate); // выводим прочитанные данные
}


void NinthTask::on_authorSearch_clicked()
{
    QString outAuthor =""; // для вывода в textEdit
    string author = ui->inLineEdit->text().toStdString(); // получаем автора из inLineEdit
    for(std::vector<Book>::iterator i = database.begin(); i<database.end();i++)
    {// проходимся по всему вектору и выводим только то, что соответствует условию
        if(i->author == author)
            outAuthor.append(QString::fromStdString(i->name+", "+i->author+", "
                                                +i->publisher+", ")+QString::number(i->year)+"\n");
    };
    ui->outTextEdit->setText(outAuthor); // выводим прочитанные данные
}


void NinthTask::on_nameSearch_clicked()
{
    QString outName = ""; // для вывода в textEdit
    string key = ui->inLineEdit->text().toStdString(); // получаем слово для поиска в названии из inLineEdit
    for(std::vector<Book>::iterator i = database.begin(); i<database.end();i++)
    {// проходимся по всему вектору и выводим только то, что соответствует условию
        if(i->name.find(key)!=std::string::npos) //поиск подстроки(ключевого слова) в названии
        // find() возвращает позицию первого символа исходной строки, где найдена подстрока
        // и если эта позиция не равна -1 (std::string::npos), то значит ключевое слово найдено в названии
            outName.append(QString::fromStdString(i->name+", "+i->author+", "
                                                 +i->publisher+", ")+QString::number(i->year)+"\n");
    };
    ui->outTextEdit->setText(outName); // выводим прочитанные данные
};


void NinthTask::on_pubSearch_clicked()
{
    QString outPub = ""; // для вывода в textEdit
    string publisher = ui->inLineEdit->text().toStdString(); // получаем издательства из inLineEdit
    for(std::vector<Book>::iterator i = database.begin(); i<database.end();i++)
    {// проходимся по всему вектору и выводим только то, что соответствует условию
        if(i->publisher == publisher)
            outPub.append(QString::fromStdString(i->name+", "+i->author+", "
                                                 +i->publisher+", ")+QString::number(i->year)+"\n");
    };
    ui->outTextEdit->setText(outPub); // выводим прочитанные данные
}

void NinthTask::on_delPushButton_clicked()
{// функция, которая очищает данные в векторе и поля на экране
    database.clear();
    ui->inLineEdit->setText("");
    ui->outTextEdit->setText("");
}
