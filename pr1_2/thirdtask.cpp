#include "thirdtask.h"
#include "ui_thirdtask.h"
#include <iostream>
#include <vector>
using namespace std;

ThirdTask::ThirdTask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThirdTask)
{
    ui->setupUi(this);
}

ThirdTask::~ThirdTask()
{
    delete ui;
}

std::vector<string> inputVector = {};

void ThirdTask::on_sortPushButton_clicked()
{
    QString out;
    //std::vector<string> inputVector = {};
    QStringList data = ui->inputTextEdit->toPlainText().split('\n');

    for(int i=0;i<data.size();i++)
    {
       inputVector.push_back(data[i].toUtf8().constData());
    };

    sort(inputVector.begin(),inputVector.end()); // сортировка по алфавиту


    if(inputVector.empty())
        out.append(QString::fromStdString("Vector is empty!"));
    else{
        for(size_t i=0;i<inputVector.size();i++)
        {
           out.append(QString::fromStdString(inputVector.at(i))+'\n');
        };
    };
    ui->outputTextEdit->setText(out);
}


void ThirdTask::on_FruitPushButton_clicked()
{
    QString out;
    if(inputVector.empty())
        out.append(QString::fromStdString("Vector is empty!"));
    else{
        for(size_t i=0;i<inputVector.size();i++)
        {
            if(inputVector.at(i)[0] == 'a'){
                out.append(QString::fromStdString(inputVector.at(i))+'\n');
            }
        };
    };
    ui->outputTextEdit->setText(out);
};


void ThirdTask::on_deletePushButton_clicked()
{
    QString out;
    std::vector<string> citrus = {"lemon","lime","mandarin","orange","grapefruit"};
    std::vector<string>::const_iterator i = inputVector.begin();

    while(i != inputVector.end()) {
        for(std::vector<string>::const_iterator j = citrus.begin(); j != citrus.end(); ++j){
            if(*i == *j){
                inputVector.erase(i);
                i--;
            };
        };
        i++;
    };

    if(inputVector.empty())
        out.append(QString::fromStdString("Vector is empty!"));
    else
        for(size_t i=0;i<inputVector.size();i++)
            out.append(QString::fromStdString(inputVector.at(i))+'\n');
    ui->outputTextEdit->setText(out);
};


void ThirdTask::on_pushButton_clicked()
{
    inputVector.clear();
    ui->inputTextEdit->setText("");
    ui->outputTextEdit->setText("");
}

