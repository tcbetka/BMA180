#include "mainwindow.h"
#include "BMA180Accelerometer.h"
#include "ui_mainwindow.h"
#include <unistd.h>
#include <QString>

#define I2C_BUS_1   1
#define BMA180_DDR  0x40


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    BMA180Accelerometer* accelerometer = new BMA180Accelerometer(I2C_BUS_1, BMA180_DDR);
}

MainWindow::~MainWindow()
{
    delete accelerometer;
    delete ui;
}

void MainWindow::on_btnClearValues_clicked()
{
    ui->xValue->setText("");
    ui->yValue->setText("");
    ui->zValue->setText("");
}

void MainWindow::on_btnClose_clicked()
{
    this->close();
}

void MainWindow::on_btnReadSensor_clicked()
{
    bool val = configureBMA180();
    if (val)
    {
        accelerometer->readFullSensorState();
        int x = accelerometer->getAccelerationX();
        int y = accelerometer->getAccelerationY();
        int z = accelerometer->getAccelerationZ();

        ui->xValue->setText(QString::number(x));
        ui->yValue->setText(QString::number(y));
        ui->zValue->setText(QString::number(z));
    }
}

bool MainWindow::configureBMA180()
{
    // TODO: Implement logic to return status from class methods below
    bool flag = true;

    // Accelerometer Test: Use i2c-1 (bus 1) and address 0x40, as the chip is configured for that address
    accelerometer->setRange(PLUSMINUS_1_G);
    accelerometer->setBandwidth(BW_150HZ);

    // TODO: For now, simply return true
    return flag;
}
