#include "pin_menu.h"

PinMenu::PinMenu(QWidget *parent, QVBoxLayout *layout, Wire *wire, pin_types pins_type, size_t limit) :
    QWidget(parent),
    _layout(layout),
    _wire(wire),
    _limit(limit),
    _pins_type(pins_type)
{
    _radius = 15;
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
        _layout->insertWidget(2, new Pin(this, _wire, "",  _pins_type));
        ++_count;
    }
}

void PinMenu::removePin()
{
    if (_count > 0)
    {
        QLayoutItem *child;
        if ((child = _layout->takeAt(2)) != 0)
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
    return qobject_cast<Pin*>(_layout->takeAt(number)->widget());
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

