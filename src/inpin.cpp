#include "inpin.h"
#include "outpin.h"
#include "map.h"

InPin::InPin(QWidget *parent, Map *map)
    : IPin(map, parent)
{
    _neighbour = nullptr;

    this->setObjectName("inpin");
    this->setStyleSheet("background-color: black");
}


InPin::~InPin()
{
    if (_neighbour != nullptr)
        disconnectPin(_neighbour);
}

void InPin::setNeighbour(OutPin *neighbour)
{
    _neighbour = neighbour;
}

OutPin* InPin::getNeighbour()
{
    return _neighbour;
}

void InPin::connectPin(OutPin* neighbour)
{
    if (_neighbour != nullptr)
    {
        disconnectPin(_neighbour);
    }

    _neighbour = neighbour;
    
    // Получение нового сигнала после подключения.
    setStatus(neighbour->getStatus());
}

void InPin::disconnectPin(OutPin* neighbour)
{
    if (_neighbour == nullptr)
        return ;

    if (neighbour != _neighbour)
        return ;
    
    OutPin *buffer = _neighbour;
    _neighbour = nullptr;
    buffer->disconnectPin(this);

    setStatus(false);
    _map->removeWire(this);
    // перерасчёт сигнала!!!
}

void InPin::setStatus(bool status)
{
    _status = status;
    if (_status == true)
        this->setStyleSheet("background-color: red");
    else
        this->setStyleSheet("background-color: black");

    emit updateElement();
}

QString InPin::getRuleForNewElement()
{
    if (_neighbour == nullptr)
    {
        return "0";
    }

    return _neighbour->getRuleForNewElement();
}

