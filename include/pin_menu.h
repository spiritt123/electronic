#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "pin.h"

class PinMenu
{
public:
    PinMenu(int x = 0, int y = 0, int len = 50, size_t limit = 10);
 
    void setRadiusPin(double radius);
    void addPin();
    void removePin();

    Pin* getPinForNumber(size_t number);

    size_t getLimit();
    void setLimit(size_t limit);

    //void draw(sf::RenderWindow *window);
 
protected:
    size_t _limit;
    int _x, _y, _len;
    double _radius;
    std::vector<Pin> _pins;
};
