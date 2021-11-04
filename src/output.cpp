#include "output.h"

Output::Output(Map *map, QWidget *parent) : IElement(map, 1, {""}, parent) 
{
    QHBoxLayout *lauout = new QHBoxLayout();
    QString rule;
    _inpin = new InPin(this, map);

    lauout->addWidget(_inpin);

    this->setLayout(lauout);   
}

Output::~Output() {}

QString Output::getRuleForNewElement()
{
    return _inpin->getRuleForNewElement();
}

IElement* Output::copy()
{
    return new Output(_map, qobject_cast<QWidget*>(this->parent()));
}
