#include "pin_menu.h"
#include <iostream>
#include <cmath>

PinMenu::PinMenu(QWidget *parent, pin_types pins_type, 
                 int x, int y, int len, size_t limit) :
    QWidget(parent),
    _x(x),
    _y(y),
    _len(len),
    _limit(limit),
    _radius(15),
    _pins_type(pins_type)
{
    _count = 0;
}

PinMenu::~PinMenu()
{

}

void PinMenu::setRadiusPin(double radius)
{
    _radius = radius;
}

void PinMenu::addPin()
{
    if (_count < _limit)
    {
        _parent->insertWidget(2, new Pin(this, _pins_type));
        ++_count;
    }
}

void PinMenu::removePin()
{
    if (_count > 0)
    {
        QLayoutItem *child;
        if ((child = _parent->takeAt(2)) != 0)
        {
            child->widget()->hide();
            delete child;
            --_count;
        }
    }
}

//???
Pin* PinMenu::getPinForNumber(size_t number)
{
    if (number >= _count)
        return nullptr;
    QLayoutItem *child;
    return (Pin*)_parent->takeAt(number);
}

size_t PinMenu::getLimit()
{
    return _limit;
}

void PinMenu::setLimit(size_t limit)
{
    if (limit < _limit)
    {
        for (size_t i = 0; i < _limit - limit; ++i)
        {
            removePin();
        }
    }
    _limit = limit;
}

