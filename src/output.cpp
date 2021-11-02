#include "output.h"

Output::Output(Map *map, QWidget *parent) : IElement(map, 1, {""}, parent) 
{
    QHBoxLayout *lauout = new QHBoxLayout();
    QString rule;
    InPin *pin = new InPin(this, map);

    lauout->addWidget(pin);

    this->setLayout(lauout);   
}

Output::~Output() {}

IElement* Output::copy()
{
    return new Output(_map, qobject_cast<QWidget*>(this->parent()));
}
