#include "window.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>

Window::Window(QMainWindow *parent, size_t width, size_t height) : 
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

    setStyleSheet(loadStyle("css/style.css"));

    this->resize(width, height);

    _wire = new Wire(this);

    _in_menu = new InputPinMenu(ui->InputPinsList, ui->InputPins, _wire);
    _out_menu = new PinMenu(ui->OutputPinsList, ui->OutputPins, _wire, input_pin);
    _element_menu = new ElementMune(ui->ListElements, ui->ListElementsLayout, _wire);
    //_element_menu->loadNewElementFormFile("elements/or.el");
    //_element_menu->saveAllElementInFile("elements/or+.el");
    
}

Window::~Window()
{
    delete ui;
}

QString Window::loadStyle(QString path)
{
    QString data;
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return "";

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        data += line + "\n";
    }
    return data;
}
   
void Window::on_AddInputPin_clicked()
{
    _in_menu->addPin();
}

void Window::on_RemoveInputPin_clicked()
{
    _in_menu->removePin();
}

void Window::on_AddOutputPin_clicked()
{
    _out_menu->addPin();
}

void Window::on_RemoveOutputPin_clicked()
{
    _out_menu->removePin();
}


