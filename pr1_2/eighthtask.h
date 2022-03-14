#ifndef EIGHTHTASK_H
#define EIGHTHTASK_H

#include <QDialog>

namespace Ui {
class EighthTask;
}

class EighthTask : public QDialog
{
    Q_OBJECT

public:
    explicit EighthTask(QWidget *parent = nullptr);
    ~EighthTask();

private slots:

    void on_delPushButton_clicked();

    void on_intOperation_clicked();

    void on_CharOperation_clicked();

    void on_bitsetOperation_clicked();

private:
    Ui::EighthTask *ui;
};

#endif // EIGHTHTASK_H
