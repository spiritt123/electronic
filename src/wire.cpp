#include "wire.h"
#include "map.h"
#include "element.h"
#include <QDebug>
#include "input_pin_menu.h"
#include "pin_menu.h"
//#include <QPoint>

Wire::Wire(QWidget *parent, Map *map) : 
    QWidget(parent),
    _map(map)
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

    if (second->getPinType() == output_pin)
    {
        Pin *buffer = second;
        second = first;
        first = buffer;
    }

    qDebug() << "second " <<  second;

    first->disconnectPin(first->getNeighbour());
    second->disconnectPin(second->getNeighbour());
    first->connectPin(second);
    second->connectPin(first);

    /*if (sizeof(qobject_cast<QWidget*>(first->parent()) ) == sizeof(new InputPinMenu(nullptr, nullptr, nullptr)))
    {
        emit _map->drawWire(
            QPoint(-15, qobject_cast<QWidget*>(first)->y() -15),
            qobject_cast<QWidget*>(second->parent())->pos() + second->pos() + QPoint(15, 15)
            );
    }
    
    if (sizeof(qobject_cast<QWidget*>(second->parent()) ) == sizeof(new PinMenu(nullptr, nullptr, nullptr)))
    {
        emit _map->drawWire(
            qobject_cast<QWidget*>(second->parent())->pos() + second->pos() + QPoint(15, 15),
            QPoint(qobject_cast<QWidget*>(first)->y() -15, qobject_cast<QWidget*>(first)->y() -15)
            );
    }*/

    //_wires.push_back(std::make_pair(first, second));

    emit _map->drawWire(
            QPoint(
                qobject_cast<QWidget*>(first->parent())->geometry().x(),
                qobject_cast<QWidget*>(first->parent())->geometry().y()
            ) + first->pos() + QPoint(15, 15),
            QPoint(
                qobject_cast<QWidget*>(second->parent())->geometry().x(),
                qobject_cast<QWidget*>(second->parent())->geometry().y()
            ) + second->pos() + QPoint(15, 15)
            );
    
    qDebug() << qobject_cast<QWidget*>(first)->pos();
    qDebug() << qobject_cast<QWidget*>(first->parent())->pos();
    qDebug() << "==================================";
    
    first  = nullptr;
    second = nullptr;
}

