#include "seventhtask.h"
#include "ui_seventhtask.h"

SeventhTask::SeventhTask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SeventhTask)
{
    ui->setupUi(this);
}

SeventhTask::~SeventhTask()
{
    delete ui;
}

    QString out;

void Printer(int i){
    out.append(QString::number(i)+" ");
}

void SeventhTask::on_firstPushButton_clicked()
{
    out = "";
    std::vector<int> squares(100);
    for(size_t i=0; i<squares.size(); i++){
        squares[i] = (i+1)*(i+1);
    };
    for_each(squares.begin(), squares.end(), Printer);
    ui->FirstTextEdit->setText(out);
};


void SeventhTask::on_secondPushButton_clicked()
{
    out = "";
    std::vector<int> roots(100);
    for(size_t i=0; i<roots.size(); i++){
        roots[i] = (i+1);
    };

    for_each(roots.begin(), roots.end(), Printer);
    ui->secondTextEdit->setText(out);
};

