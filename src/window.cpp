
#include <functional>
#include "window.h"
#include "ui_mainwindow.h"
#include <iostream>

Window::Window(QMainWindow *parent, size_t height, size_t width) : 
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

    //Pin *pin = new Pin(this);
    //connect(pin, SIGNAL(click(Pin*)), this, SLOT(wire(Pin*)) );
    setStyleSheet(
            "QPushButton#pin {\n"
                "border-radius: 15px;\n"
                "max-width: 30px;\n"
                "height: 30px;\n"
                "background-position: center;\n"
                "margin-left: 65px\n"
                "}\n"
                
                );
    
    //ui->InputPins->insertWidget(2, pin);

    _height = height;
    _width = width;
    //_in_menu = InputPinMenu(50, 0, _height);
    _out_menu = new PinMenu(ui->OutputPinsList, output_pin, _width - 50, 0, _height);
    _out_menu->setLayout(ui->OutputPins);
}

Window::~Window()
{
    delete ui;
}

void Window::wire(Pin *pin)
{
    static Pin *first  = nullptr;

    if (first->getPinType() == pin->getPinType())
        return ;
    if (first == nullptr)
    {
        first = pin;
        std::cout << "first " << pin << "\n";
        return ;
    }

    
    first = nullptr;
    std::cout << "second " <<  pin << "\n";
}
    
void Window::on_AddOutputPin_clicked()
{
    _out_menu->addPin();
}

void Window::on_AddInputPin_clicked()
{

}

void Window::on_RemoveOutputPin_clicked()
{
    _out_menu->removePin();
}

void Window::on_RemoveInputPin_clicked()
{

}

/*
void Window::wire()
{
    Pin *start = _in_menu.getPinForNumber(0);
    Pin *end   = _out_menu.getPinForNumber(0);
    if (start != nullptr)
        start->setNeighbour(end);
    if (end != nullptr)
        end->setNeighbour(start);
}
*/


