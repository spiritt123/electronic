#pragma once

#include <QWidget>

#include "map.h"

class Input : public IElement
{
    Q_OBJECT
public:
    Input(Map *map, QWidget *parent = 0);
    ~Input();

    virtual IElement* copy() override;

private:
};
