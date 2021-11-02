#pragma once

#include <QWidget>
#include <QString>

#include "map.h"

class Input : public IElement
{
    Q_OBJECT
public:
    Input(Map *map, QWidget *parent = 0, QString rule = "a");
    ~Input();

    virtual IElement* copy() override;

private:
};
