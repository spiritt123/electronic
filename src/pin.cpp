#include <iostream>

#include "pin.h"

Pin::Pin(Element *parent, bool status, Pin *neighbour)
{
    _parent = parent;
    _status = status;
    _neighbour = neighbour;
}

Pin::~Pin()
{
}

bool Pin::changeStatus()
{
    _status ^= 1;
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

void Pin::setParent(Element *parent)
{
    _parent = parent;
}

bool Pin::getStatus()
{
    return _status;
}

Pin* Pin::getNeighbour()
{
    return _neighbour;
}

Element* Pin::getParent()
{
    return _parent;
}
