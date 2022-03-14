#include "secondtask.h"
#include "ui_secondtask.h"

SecondTask::SecondTask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondTask)
{
    ui->setupUi(this);
}

SecondTask::~SecondTask()
{
    delete ui;
}

std::vector<char> engAlphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                                 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
                                 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

void SecondTask::on_pushButtonFwd_clicked()
{
    QString out;
    for (std::vector<char>::const_iterator i = engAlphabet.begin(); i != engAlphabet.end(); ++i)
        out += QString(QChar::fromLatin1(*i));
    ui->Out2textEdit->setText(out);
}


void SecondTask::on_pushButtonRew_clicked()
{
    QString out;
    for (std::vector<char>::const_iterator i = engAlphabet.end(); i >= engAlphabet.begin(); --i)
        out += QString(QChar::fromLatin1(*i));
    ui->Out2textEdit->setText(out);
}
