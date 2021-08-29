#pragma once

#include <QObject>
#include "pin.h"

class Wire : public QObject
{
    Q_OBJECT
public:
    Wire(QObject *parent);
    ~Wire();

public slots:
    void createWire(Pin *pin);

private:
    //Pin *p;
};

