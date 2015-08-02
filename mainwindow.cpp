#include "mainwindow.h"
#include "BMA180Accelerometer.h"
#include "workerthread.h"
#include "ui_mainwindow.h"
#include <unistd.h>
#include <QString>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wkThread = new WorkerThread;

    // Make the signal/slot connection between the threads
    connect(wkThread, SIGNAL(progressChanged(AccelValues*)), SLOT(onProgressChanged(AccelValues*)));

    // Invoke the WorkerThread::run() in a new thread
    wkThread->start();

    ui->btnReadSensor->setEnabled(false);
    ui->btnClearValues->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnClearValues_clicked()
{
    clearLabels();
}

void MainWindow::clearLabels()
{
    ui->xValue->setText("");
    ui->yValue->setText("");
    ui->zValue->setText("");
}

void MainWindow::on_btnClose_clicked()
{
    // TODO: Terminate the thread gracefully by implementing the QThread::terminated() signal
    //      See: http://doc.qt.io/qt-4.8/qthread.html#terminate
    // THIS IS NOT the best way to do this--should just set a wkThread flag, that is then checked
    //  in that thread when a read is set to occur. If the user requests a stop, then set the flag
    //  to false so the read won't happen. Then terminate the thread after that...
    wkThread->terminate();

    // For now we can simply wait until the thread gets terminated, and then close the form
    if (wkThread->wait()) {
        this->close();
    }
}


void MainWindow::onProgressChanged(struct AccelValues *vals)
{
    //qDebug() << "Signal received";
    //clearLabels();

    // Get these values from the worker thread, and update the GUI
    ui->xValue->setText(QString::number(vals->x));
    ui->yValue->setText(QString::number(vals->y));
    ui->zValue->setText(QString::number(vals->z));
    ui->tempValue->setText(QString::number(vals->temp));
}


void MainWindow::on_btnReadSensor_clicked()
{
    //TODO: May need to reimplement this later
}

