#pragma once

#include <QWidget>

#include "pin.h"

class Map;

class Wire : public QWidget
{
    Q_OBJECT
public:
    Wire(QWidget *parent, Map *map);
    ~Wire();

public slots:
    void createWire(Pin *pin);

private:
    Map *_map;
    //std::vector<std::pair<Pin*, Pin*>> _wires;
    //Pin *p;
};

