#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "input_pin_menu.h"
#include "pin_menu.h"
#include "element.h"

class Window
{
public:
    Window(size_t height = 640, size_t width = 480);
    ~Window();
    void wire();
    void closeWindow();
    void start();

    void draw();

private:
    //sf::RenderWindow *_window;
    size_t _height, _width;
    
    InputPinMenu _in_menu;
    PinMenu _out_menu;

    std::vector<Element*> _elements;
};
