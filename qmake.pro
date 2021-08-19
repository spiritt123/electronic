QT += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

VPATH = src
INCLUDEPATH = include

SOURCES += src/*.cpp

HEADERS += include/*.h

FORMS += \
    mainwindow.ui

