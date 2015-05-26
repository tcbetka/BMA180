#-------------------------------------------------
#
# Project created by QtCreator 2015-05-24T19:35:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BMA180_DM
TEMPLATE = app


SOURCES += BMA180Accelerometer.cpp \
    mainwindow.cpp \
    main.cpp \
    workerthread.cpp

HEADERS += \
    BMA180Accelerometer.h \
    mainwindow.h \
    workerthread.h \
    utility.h

FORMS += \
    mainwindow.ui
