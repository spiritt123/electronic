#include <iostream>

#include "pin.h"

Pin::Pin(QWidget *parent, pin_types pin_type, bool status, Pin *neighbour) :
    QPushButton(parent),
    _pin_type(pin_type),
    _status(status),
    _neighbour(neighbour)
{
    this->setObjectName("pin");
    this->setStyleSheet("background-color: black");
    connect(this, SIGNAL( clicked() ), this, SLOT( getPointPin() ));
}

Pin::~Pin()
{
    if (_neighbour != nullptr)
        disconnectPin(_neighbour);
}

void Pin::getPointPin()
{
    emit click(this);
}

bool Pin::changeStatus()
{
    _status ^= 1;
    
    if (_status == true)
        this->setStyleSheet("background-color: red");
    else
        this->setStyleSheet("background-color: black");
    std::cout << _status << "\n";

    return _status;
}

void Pin::setStatus(bool status)
{
    _status = status;
}

void Pin::setNeighbour(Pin *neighbour)
{
    _neighbour = neighbour;
}

void Pin::setPinType(pin_types pin_type)
{
    _pin_type = pin_type;
}

bool Pin::getStatus()
{
    return _status;
}

Pin* Pin::getNeighbour()
{
    return _neighbour;
}

pin_types Pin::getPinType()
{
    return _pin_type;
}

void Pin::connectPin(Pin* neighbour)
{
    if (neighbour->getPinType() == _pin_type || neighbour == nullptr)
        return ;

    _neighbour = neighbour;
    
    // Получение нового сигнала после подключения.
    if (_pin_type == input_pin)
        _status = neighbour->getStatus();
}

void Pin::disconnectPin(Pin* neighbour)
{
    if (neighbour != _neighbour)
        return;
    
    Pin *buffer = _neighbour;
    _neighbour = nullptr;
    buffer->disconnectPin(this);

    if (_pin_type == input_pin)
    {
        _status = false;
        // перерасчёт сигнала!!!
    }
}

