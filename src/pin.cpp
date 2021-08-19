
#include "pin.h"

Pin::Pin(Element *parent, bool status, Pin *source, Pin *drain)
{
    _parent = parent;
    _status = status;
    _source = source;
    _drain  = drain;
}

Pin::~Pin()
{
    if (_source != nullptr)
        delete _source;
    if (_drain != nullptr)
        delete _drain;
    if (_parent != nullptr)
        delete _parent;
}

void Pin::changeStatus()
{
    _status ^= 1;
}

void Pin::setStatus(bool status)
{
    _status = status;
}

void Pin::setSource(Pin *source)
{
    if (_source != nullptr)
        delete _source;
    _source = source;
}

void Pin::setDrain(Pin *drain)
{
    if (_drain != nullptr)
        delete _drain;
    _drain = drain;
}

void Pin::setParent(Element *parent)
{
    if (_parent != nullptr)
        delete _parent;
    _parent = parent;
}

bool Pin::getStatus()
{
    return _status;
}

Pin* Pin::getSource()
{
    return _source;
}

Pin* Pin::getDrain()
{
    return _drain;
}

Element* Pin::getParent()
{
    return _parent;
}
