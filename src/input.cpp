#include "input.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QString>
//#include <>

Input::Input(Map *map, QWidget *parent, QString rule)
    : IElement(map, 0, {rule}, parent)
{
    QHBoxLayout *switch_switch = new QHBoxLayout();
    QPushButton *switch_pin = new QPushButton("on/off");

    OutPin *pin = new OutPin(this, map, "a");
        
    connect(switch_pin, SIGNAL(clicked()), pin, SLOT(changeStatus()));

    switch_switch->addWidget(switch_pin);
    switch_switch->addWidget(pin);

    this->setLayout(switch_switch);
}

Input::~Input() {}

IElement* Input::copy()
{
    return new Input(_map, qobject_cast<QWidget*>(this->parent()));
}
