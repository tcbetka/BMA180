#include "workerthread.h"
#include <QDebug>


WorkerThread::WorkerThread(QObject *parent) :
    QThread(parent)
{
    accelerometer = new BMA180Accelerometer(I2C_BUS_1, BMA180_DDR);
    timer = new QTimer(this);
    vals = new struct AccelValues;

    connect(timer, SIGNAL(timeout()), this, SLOT(readSensors()));
}

void WorkerThread::readSensors()
{
    //qDebug() << "Sensors read";
    accelerometer->readFullSensorState();
    vals->x = accelerometer->getAccelerationX();
    vals->y = accelerometer->getAccelerationY();
    vals->z = accelerometer->getAccelerationZ();
    vals->temp = accelerometer->getTemperature();

    //qDebug() << "Emit: " << vals->x << ", " << vals->y << ", " << vals->z;
    emit progressChanged(vals);
}

// This method actually gets called from the client (GUI) thread
void WorkerThread::run()
{
    // If we can configure the accelerometer, we'll start the timer at a 1000ms interval
    if (configureBMA180())
    {
        qDebug() << "Starting the timer";
        timer->start(250);
    }
}

bool WorkerThread::configureBMA180()
{
    qDebug() << "Configuring BMA180";

    // TODO: Implement logic to return status from class methods below
    bool flag = true;

    // Accelerometer Test: Use i2c-1 (bus 1) and address 0x40, as the chip is configured for that address
    accelerometer->setRange(PLUSMINUS_1_G);
    accelerometer->setBandwidth(BW_150HZ);

    // TODO: For now, simply return true
    return flag;
}
