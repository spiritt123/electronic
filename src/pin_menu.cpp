#include "pin_menu.h"
#include <iostream>
#include <cmath>

PinMenu::PinMenu(int x, int y, int len, size_t limit)
{
    _x = x;
    _y = y;
    _len = len;
    _limit = limit;
    _radius = 15;
}

void PinMenu::setRadiusPin(double radius)
{
    _radius = radius;
}

void PinMenu::addPin()
{
    if (_pins.size() < _limit)
    {
        _pins.push_back(Pin());
    }
}

Pin* PinMenu::getPinForNumber(size_t number)
{
    if (number >= _pins.size())
        return nullptr;
    return &_pins[number];
}
void PinMenu::removePin()
{
    //_input_pins.back().getSource().removeSource();
    if (_pins.size() > 0)
    {
        _pins.pop_back();
    }
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

/*
void PinMenu::draw(sf::RenderWindow *window)
{
    size_t count  = _pins.size();
    double part   = 0.8;
    double offset = (1 - part) / 2 * _len;
    for (size_t i = 0; i < count; ++i)
    {
        sf::CircleShape circle(_radius);
        circle.setOrigin(_radius, _radius);
        if (_pins[i].getStatus() == true)
            circle.setFillColor(sf::Color(255, 0, 0));
        else
            circle.setFillColor(sf::Color(0, 0, 0));
        circle.move(_x, offset + _len * part * (i + 1) / (count + 1));
        window->draw(circle);
    }
}
*/

