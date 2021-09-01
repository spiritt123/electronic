#include "pin.h"
#include "wire.h"

#include <QDebug>

Pin::Pin(QWidget *parent, Wire *wire, pin_types pin_type, bool status, Pin *neighbour) :
    QPushButton(parent),
    _pin_type(pin_type),
    _status(status),
    _neighbour(neighbour)
{
    if (pin_type == input_pin)
        this->setObjectName("inpin");
    else
        this->setObjectName("outpin");
    
    this->setStyleSheet("background-color: black");
    
    connect(this, SIGNAL( clicked() ), this, SLOT( getPointPin() ));
    
    if (wire != nullptr)
        connect(this, SIGNAL( click(Pin*) ), (Wire*)wire, SLOT( createWire(Pin*) ));
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
    
    setStatus(_status);

    return _status;
}

void Pin::setStatus(bool status)
{
    _status = status;

    if (_status == true)
        this->setStyleSheet("background-color: red");
    else
        this->setStyleSheet("background-color: black");

    if (_pin_type == output_pin && _neighbour != nullptr)
        _neighbour->setStatus(_status);
    emit updateElement();
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
        setStatus(neighbour->getStatus());
}

void Pin::disconnectPin(Pin *neighbour)
{
    if (_neighbour == nullptr)
        return ;

    if (neighbour != _neighbour)
        return ;
    
    Pin *buffer = _neighbour;
    _neighbour = nullptr;
    buffer->disconnectPin(this);

    if (_pin_type == input_pin)
    {
        setStatus(false);
        // перерасчёт сигнала!!!
    }
}

/*
void Pin::setRule(QString rule)
{
    _rule = rule;
}

QString Pin::getRule()
{
    return _rule;
}

void Pin::clearOutPath()
{
    if (_pin_type == input_pin)
    {
        _rule = "";
    }
}

*/
