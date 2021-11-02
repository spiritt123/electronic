#pragma once

#include <QWidget>
#include <QVBoxLayout>

#include <vector>

#include "map.h"

class Output : public IElement
{
    Q_OBJECT
public:
    Output(Map *map, QWidget *parent = 0);
    ~Output();

    virtual IElement* copy() override;

protected:
};
