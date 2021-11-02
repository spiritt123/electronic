#pragma once

#include "ipin.h"

class OutPin;
class Map;

class InPin : public IPin
{
public:
    InPin(QWidget *parent, Map *map);
    ~InPin();

    void setNeighbour(OutPin *neighbour);
    OutPin*  getNeighbour();

    virtual QString getName() override {return "inpin";}
    virtual void setStatus(bool status) override;

    void connectPin(OutPin* neighbour);
    void disconnectPin(OutPin* neighbour);


private:
    OutPin* _neighbour;
};

