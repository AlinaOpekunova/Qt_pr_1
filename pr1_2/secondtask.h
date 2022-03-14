#ifndef SECONDTASK_H
#define SECONDTASK_H

#include <QDialog>

namespace Ui {
class SecondTask;
}

class SecondTask : public QDialog
{
    Q_OBJECT

public:
    explicit SecondTask(QWidget *parent = nullptr);
    ~SecondTask();

private slots:

    void on_pushButtonFwd_clicked();

    void on_pushButtonRew_clicked();

private:
    Ui::SecondTask *ui;
};

#endif // SECONDTASK_H
