#include "input_pin_menu.h"
#include <iostream>
#include <cmath>

InputPinMenu::InputPinMenu(int x, int y, int len, size_t limit) : 
                   PinMenu(x, y, len, limit)
{
}

double distance(sf::Vector2f start, sf::Vector2f end)
{
    double dx = end.x - start.x;
    double dy = end.y - start.y;
    return sqrt(dx * dx + dy * dy);
}
/*
void InputPinMenu::click(sf::Vector2i mouse_position, size_t height)
{
    size_t count  = _pins.size();
    double part   = 0.8;
    double offset = (1 - part) / 2 * height;
    size_t i = ((mouse_position.y + _radius - offset) * (_pins.size() + 1) / (height * part)) - 1;
    if (distance(sf::Vector2f(_x, offset + height * part * (i + 1) / (count + 1)),
                 sf::Vector2f(mouse_position.x, mouse_position.y)) <= _radius)
    {
        bool status = _pins[i].changeStatus();
        Pin *pin = _pins[i].getNeighbour();
        if (pin != nullptr)
            pin->setStatus(status);
        std::cout << "click on " << i + 1 << " pin\n";
    }
}*/
