#pragma once

//#include "element.h"
class Element;

class Pin
{
public:
    Pin(Element *parent = nullptr, bool status = false, Pin *source = nullptr, Pin *drain = nullptr);
    ~Pin();

    void changeStatus();

    void setStatus(bool status);
    void setSource(Pin *source);
    void setDrain(Pin *drain);
    void setParent(Element *parent);

    bool  getStatus();
    Pin*  getSource();
    Pin*  getDrain();
    Element* getParent();

private:
    bool _status;
    Pin* _source;
    Pin* _drain;
    Element* _parent;
};

