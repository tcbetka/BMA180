#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>

struct accelValues
{
    int x;
    int y;
    int z;
};

class WorkerThread : public QThread
{
    Q_OBJECT
public:
    explicit WorkerThread(QObject *parent = 0);
    void run();
    
signals:
    void progressChanged(struct accelValues values);
    
public slots:

private:
    QTimer* timer;
    
};

#endif // WORKERTHREAD_H
