
#include <functional>
#include <iostream>
#include "window.h"
#include <map>

Window::Window(size_t height, size_t width)
{
    _height = height;
    _width = width;
    //_window = new sf::RenderWindow(sf::VideoMode(width, height), "Press H for insormation");
    //_window->setFramerateLimit(30);
    _in_menu = InputPinMenu(50, 0, _height);
    _out_menu = PinMenu(_width - 50, 0, _height);
}

Window::~Window()
{
    //delete _window;
}

void Window::closeWindow()
{
    //_window->close();
}


void Window::wire()
{
    Pin *start = _in_menu.getPinForNumber(0);
    Pin *end   = _out_menu.getPinForNumber(0);
    if (start != nullptr)
        start->setNeighbour(end);
    if (end != nullptr)
        end->setNeighbour(start);
}

void Window::start()
{
    std::map<sf::Keyboard::Key, std::function<void()>> keys_functions;
    keys_functions[sf::Keyboard::Escape] = std::bind(&Window::closeWindow, this);

    keys_functions[sf::Keyboard::Z]      = std::bind(&InputPinMenu::addPin, &_in_menu);
    keys_functions[sf::Keyboard::X]      = std::bind(&InputPinMenu::removePin, &_in_menu);
    keys_functions[sf::Keyboard::C]      = std::bind(&PinMenu::addPin, &_out_menu);
    keys_functions[sf::Keyboard::V]      = std::bind(&PinMenu::removePin, &_out_menu);
    
    //keys_functions[sf::Keyboard::Num1]   = std::bind(&PinMenu::removePin, &_out_menu);
    keys_functions[sf::Keyboard::W]   = std::bind(&Window::wire, this);


/*
    while (_window->isOpen())
    {
        sf::Event event;
        while (_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _window->close();
            if (event.type == sf::Event::KeyPressed)
            {
                auto ss = keys_functions[event.key.code];
                if (!ss)
                    continue;
                ss();
            }
            
            if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i position = sf::Mouse::getPosition(*_window);
                _in_menu.click(position, _height);
            }
        }
        
        _window->clear(sf::Color(55, 71, 79, 1));

        draw();

        _window->display();
    }
    */
}

void Window::draw()
{
    //_in_menu.draw(_window);
    //_out_menu.draw(_window);
}

