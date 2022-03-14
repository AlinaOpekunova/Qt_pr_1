#ifndef THIRDTASK_H
#define THIRDTASK_H

#include <QDialog>

namespace Ui {
class ThirdTask;
}

class ThirdTask : public QDialog
{
    Q_OBJECT

public:
    explicit ThirdTask(QWidget *parent = nullptr);
    ~ThirdTask();

private slots:

    void on_sortPushButton_clicked();

    void on_FruitPushButton_clicked();

    void on_deletePushButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::ThirdTask *ui;
};

#endif // THIRDTASK_H
