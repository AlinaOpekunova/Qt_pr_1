#include "fourthtask.h"
#include "ui_fourthtask.h"
#include <vector>
using namespace std;
#include<iostream>

FourthTask::FourthTask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FourthTask)
{
    ui->setupUi(this);
}

FourthTask::~FourthTask()
{
    delete ui;
}

std::vector<QString> dates = {};
QStringList temp;

QMap<QString, int> monthes = {{"Jan",1},{"Feb",2},{"Mar",3},{"Apr",4},{"May",5},{"Jun",6},
                          {"Jul",7},{"Aug",8},{"Sep",9},{"Oct",10},{"Nov",11},{"Dec",12}};

void FourthTask::on_sortPushButton_clicked()
{
    QString out;
    temp = ui->inputTextEdit->toPlainText().split('\n');

    for(QList<QString>::Iterator i = temp.begin(); i < temp.end(); i++)
    {
        for(QList<QString>::Iterator j = temp.begin(); j < temp.end()-1; j++)
        {
            if(j->mid(3).toInt()<(j+1)->mid(3).toInt())
            {
                std::swap(*j,*(j+1));
            }
        }
    };

    for(QList<QString>::Iterator i = temp.begin(); i < temp.end(); i++)
    {
        for(QList<QString>::Iterator j = temp.begin(); j < temp.end()-1; j++)
        {
            if((monthes.value(j->mid(0,3)) < monthes.value((j+1)->mid(0,3)))
                    &&(j->mid(3).toInt()==(j+1)->mid(3).toInt()))
            {
                std::swap(*j,*(j+1));
            }
        }
    };

    if(temp.empty())
        out.append(QString::fromStdString("Данные не введены!"));
    else{
        for(int i=0;i<temp.size();i++)
        {
           out.append(temp[i]+'\n');
        };
    };
    ui->outputTextEdit->setText(out);
};


void FourthTask::on_delPushButton_clicked()
{
    temp.clear();
    ui->inputTextEdit->setText("");
    ui->outputTextEdit->setText("");
};
