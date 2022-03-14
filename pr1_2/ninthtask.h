#ifndef NINTHTASK_H
#define NINTHTASK_H

#include <QDialog>

namespace Ui {
class NinthTask;
}

class NinthTask : public QDialog
{
    Q_OBJECT

public:
    explicit NinthTask(QWidget *parent = nullptr);
    ~NinthTask();

private slots:
    void on_readFile_clicked();

    void on_dateSearch_clicked();

    void on_authorSearch_clicked();

    void on_nameSearch_clicked();

    void on_pubSearch_clicked();

    void on_delPushButton_clicked();

private:
    Ui::NinthTask *ui;
};

#endif // NINTHTASK_H
