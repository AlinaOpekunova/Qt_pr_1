#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_secondTask_clicked();

    void on_thirdTask_clicked();

    void on_fourthTask_clicked();

    void on_seventhTask_clicked();

    void on_fifthTask_clicked();

    void on_eighthTask_clicked();

    void on_ninthTask_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
