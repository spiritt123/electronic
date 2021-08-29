#pragma once

#include <QWidget>
#include "pin_menu.h"
#include "wire.h"

class InputPinMenu : public PinMenu
{
public:
    InputPinMenu(QWidget *parent, QVBoxLayout *layout, Wire *wire, size_t limit = 10);

    void addPin();
    void removePin();

private:
};
