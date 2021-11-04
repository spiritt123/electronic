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
    src/ipin.cpp \
    src/inpin.cpp \
    src/outpin.cpp \
    src/ielement.cpp \
    src/input.cpp \
    src/output.cpp \
    src/element.cpp \
    src/element_menu.cpp \
    src/new_element_button.cpp \
    src/map.cpp \
    src/creator_new_elements.cpp \
    src/menu.cpp \
    src/settings.cpp 

#src/*.cpp
#DESTDIR = $$[QT_INSTALL_PLUGINS]/generic

HEADERS += include/*.h

FORMS += \
    mainwindow.ui \
    menu.ui \
    settings.ui

