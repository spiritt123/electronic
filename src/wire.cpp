#include "wire.h"
#include <QDebug>
//#include <QPoint>

Wire::Wire(QObject *parent) : QObject(parent)
{

}

Wire::~Wire()
{}


void Wire::createWire(Pin *pin)
{
    static Pin *first  = nullptr;
    static Pin *second = nullptr;

    if (first == nullptr)
    {
        first = pin;
        qDebug() << "first " << first;
        return ;
    }

    second = pin;
    if (first->getPinType() == second->getPinType())
        return ;

    qDebug() << "second " <<  second;

    first->disconnectPin(first->getNeighbour());
    second->disconnectPin(second->getNeighbour());
    first->connectPin(second);
    second->connectPin(first);

    first  = nullptr;
    second = nullptr;
}

