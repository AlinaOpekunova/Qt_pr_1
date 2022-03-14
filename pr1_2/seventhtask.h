#ifndef SEVENTHTASK_H
#define SEVENTHTASK_H

#include <QDialog>

namespace Ui {
class SeventhTask;
}

class SeventhTask : public QDialog
{
    Q_OBJECT

public:
    explicit SeventhTask(QWidget *parent = nullptr);
    ~SeventhTask();

private slots:
    void on_firstPushButton_clicked();

    void on_secondPushButton_clicked();

private:
    Ui::SeventhTask *ui;
};

#endif // SEVENTHTASK_H
