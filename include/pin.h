#pragma once

//#include "element.h"
class Element;

class Pin
{
public:
    Pin(Element *parent = nullptr, bool status = false, Pin *neighbour = nullptr);
    ~Pin();

    bool changeStatus();

    void setStatus(bool status);
    void setNeighbour(Pin *neighbour);
    void setParent(Element *parent);

    bool  getStatus();
    Pin*  getNeighbour();
    Element* getParent();

private:
    bool _status;
    Pin* _neighbour;
    Element* _parent;
};

