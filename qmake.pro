QT += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

VPATH = src
INCLUDEPATH = include

TARGET = main.out

SOURCES += \
    src/main.cpp \
    src/window.cpp \
    src/pin.cpp \
    src/pin_menu.cpp \
    src/input_pin_menu.cpp \
    src/element.cpp \
    src/element_menu.cpp \
    src/wire.cpp

#src/*.cpp
#DESTDIR = $$[QT_INSTALL_PLUGINS]/generic

HEADERS += include/*.h

FORMS += \
    mainwindow.ui

