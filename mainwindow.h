#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "utility.h"
#include "workerthread.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnClearValues_clicked();
    void on_btnClose_clicked();
    void on_btnReadSensor_clicked();

public slots:
    void onProgressChanged(struct AccelValues* vals);

private:
    Ui::MainWindow *ui;
    WorkerThread* wkThread;

    // Helper functions
    void clearLabels();
};

#endif // MAINWINDOW_H
