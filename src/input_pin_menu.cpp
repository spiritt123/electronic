#include "input_pin_menu.h"
#include "pin.h"
#include <iostream>
#include <cmath>

InputPinMenu::InputPinMenu(QWidget *parent, QVBoxLayout *layout, Wire *wire, size_t limit) : 
                   PinMenu(parent, layout, wire, output_pin, limit)
{
}

void InputPinMenu::addPin()
{
    if (_count < _limit)
    {
        QHBoxLayout *switch_switch = new QHBoxLayout();
        QPushButton *switch_pin = new QPushButton("on/off");
        Pin *pin = new Pin(this, _wire, _pins_type);
        
        connect(switch_pin, SIGNAL(clicked()), pin, SLOT(changeStatus()));

        switch_switch->addWidget(switch_pin);
        switch_switch->addWidget(pin);

        _layout->insertLayout(2, switch_switch);
        ++_count;
    }
}

void InputPinMenu::removePin()
{
    if (_count > 0)
    {
        QLayoutItem *child;
        if ((child = _layout->takeAt(2)) != 0)
        {
            auto button_child = child->layout()->takeAt(0);
            button_child->widget()->hide();
            delete button_child;

            auto pin_child = child->layout()->takeAt(0);
            pin_child->widget()->hide();
            delete pin_child;

            delete child;
            --_count;
        }
    }
}
