#include "mainwindow.h"
#include "BMA180Accelerometer.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
} // end main()

// NOTE: This code is not being used in the GUI form, however it is kept only for futuer reference
//
//cout << "The current bandwidth is: " << (int)accelerometer.getBandwidth() << endl;
//cout << "The current mode is: " << (int)accelerometer.getModeConfig() << endl;
//cout << "The current range is: " << (int)accelerometer.getRange() << endl;
//cout << "The current temperature is: " << (float)accelerometer.getTemperature() << endl;
//cout << "Current Acceleration: " << x << "," << y << "," << z << endl;
