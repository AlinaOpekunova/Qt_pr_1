#include "fifthtask.h"
#include "ui_fifthtask.h"
#include<bitset>
#include <iostream>

using namespace std;

FifthTask::FifthTask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FifthTask)
{
    ui->setupUi(this);
}

FifthTask::~FifthTask()
{
    delete ui;
}

void FifthTask::on_pushButton_clicked()
{
    QString out;
    int attendance = 0; // число дней посещения
    int fullDays = 0; // количество студентов, присутствоваших 12 дней
    int daysLess8 = 0; // количество студентов, присутствоваших менее 8 дней
    const int days = 12;
    unsigned int nStudents = ui->inputStudents->text().toInt();
    vector<bitset<days>> students(nStudents);

    for(unsigned int i=0; i<nStudents;i++)
        for(int j=0;j<days;j++)
            students[i][j] = rand() % 2; //инициализация 0 или 1 элемента bitset

    for(unsigned int i=0;i<nStudents;i++)
    {
        attendance = students[i].count(); // подсчет числа битов в bitset, равных 1

        out.append("Student "+QString::number(i+1)+": "
                   +QString::fromStdString(students[i].to_string())
                   +" - присутствовал "+QString::number(attendance)+" дня(-ей)"+'\n');

        if(attendance == days)
            fullDays++;
        else if (attendance < 8)
            daysLess8++;
        attendance = 0;
    }

    ui->outAllStud->setText(QString::number(fullDays));
    ui->outPartStud->setText(QString::number(daysLess8));
    ui->attendanceTextEdit->setText(out);
}

