#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include "BMA180Accelerometer.h"
#include "utility.h"
#include <QThread>
#include <QTimer>


class WorkerThread : public QThread
{
    Q_OBJECT
public:
    explicit WorkerThread(QObject *parent = 0);
    void run();
    struct AccelValues* vals;

signals:
    void progressChanged(struct AccelValues* values);
    
public slots:
    void readSensors();

private:
    QTimer* timer;
    BMA180Accelerometer* accelerometer;

    // Helper functions
    bool configureBMA180(void);
};

#endif // WORKERTHREAD_H
