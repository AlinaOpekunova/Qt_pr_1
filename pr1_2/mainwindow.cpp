#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondtask.h"
#include "thirdtask.h"
#include "fourthtask.h"
#include "fifthtask.h"
#include "seventhtask.h"
#include "eighthtask.h"
#include "ninthtask.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_secondTask_clicked()
{
    SecondTask window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_thirdTask_clicked()
{
    ThirdTask window;
    window.setModal(true);
    window.exec();
}


void MainWindow::on_fourthTask_clicked()
{
    FourthTask window;
    window.setModal(true);
    window.exec();
}


void MainWindow::on_fifthTask_clicked()
{
    FifthTask window;
    window.setModal(true);
    window.exec();
}


void MainWindow::on_seventhTask_clicked()
{
    SeventhTask window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_eighthTask_clicked()
{
    EighthTask window;
    window.setModal(true);
    window.exec();
}


void MainWindow::on_ninthTask_clicked()
{
    NinthTask window;
    window.setModal(true);
    window.exec();
}

