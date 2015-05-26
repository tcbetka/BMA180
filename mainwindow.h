#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "BMA180Accelerometer.h"
#include <QMainWindow>
#include <QTimer>

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
    void update();

private:
    Ui::MainWindow *ui;
    BMA180Accelerometer* accelerometer;
    QTimer* timer;

    // Helper functions
    bool configureBMA180(void);
    void clearLabels();
};

#endif // MAINWINDOW_H
