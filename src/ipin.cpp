#include <QDebug>
#include "ipin.h"
#include "map.h"

IPin::IPin(Map *map, QWidget *parent)
    : QPushButton(parent),
    _map(map)
{
    _status = false;

    connect(this, SIGNAL( clicked() ), this, SLOT( getPointPin() ));
    connect(this, SIGNAL( click(IPin*) ), (Map*)_map, SLOT( createWire(IPin*) ));
}

bool IPin::getStatus()
{
    return _status;
}

bool IPin::changeStatus()
{
    _status ^= 1;
    
    setStatus(_status);

    return _status;
}

void IPin::getPointPin()
{
    emit click(this);
}

