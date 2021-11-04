#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QString>

#include <vector>

#include "map.h"

class Output : public IElement
{
    Q_OBJECT
public:
    Output(Map *map, QWidget *parent = 0);
    ~Output();

    QString getRuleForNewElement();
    virtual IElement* copy() override;

protected:
    InPin *_inpin;
};
