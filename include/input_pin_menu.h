#pragma once

#include <vector>

#include "pin_menu.h"

class InputPinMenu : public PinMenu
{
public:
    InputPinMenu(int x = 0, int y = 0, int len = 50, size_t limit = 10);

    //void click(sf::Vector2i mouse_positio, size_t height);

private:
};
