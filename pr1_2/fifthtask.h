#ifndef FIFTHTASK_H
#define FIFTHTASK_H

#include <QDialog>

namespace Ui {
class FifthTask;
}

class FifthTask : public QDialog
{
    Q_OBJECT

public:
    explicit FifthTask(QWidget *parent = nullptr);
    ~FifthTask();

private slots:
    void on_pushButton_clicked();

private:
    Ui::FifthTask *ui;
};

#endif // FIFTHTASK_H
