#include "wire.h"
#include <QDebug>
#include <QPoint>

Wire::Wire(QObject *parent) : QObject(parent)
{

}

Wire::~Wire()
{}


void Wire::createWire(Pin *pin)
{
    static Pin *first  = nullptr;

    if (first == nullptr)
    {
        first = pin;
        qDebug() << "first " << pin;
        return ;
    }
    if (first->getPinType() == pin->getPinType())
        return ;

    qDebug() << "second " <<  pin;

    first->disconnectPin(first->getNeighbour());
    pin->disconnectPin(pin->getNeighbour());
    first->connectPin(pin);
    pin->connectPin(first);

    first = nullptr;
}

