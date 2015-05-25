#-------------------------------------------------
#
# Project created by QtCreator 2015-05-24T19:35:12
#
#-------------------------------------------------

QT       += core
QT       -= gui

TARGET = BMA180_DM
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += BMA180Accelerometer.cpp \
    EasyDriver.cpp \
    SimpleGPIO.cpp \
    TestApplication.cpp

HEADERS += \
    BMA180Accelerometer.h \
    EasyDriver.h \
    SimpleGPIO.h
