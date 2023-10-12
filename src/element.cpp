#include "element.h"
#include "inpin.h"
#include "outpin.h"

#include <string>
#include <QDebug>

Element::Element(Map *map, size_t input_pin_count, std::vector<QString> rules, QString name, QWidget *parent) : 
    IElement(map, input_pin_count, rules, parent),
    _name(name)
{
    QHBoxLayout *layout = new QHBoxLayout();
    QVBoxLayout *input_layout = new QVBoxLayout();
    QVBoxLayout *output_layout = new QVBoxLayout();
    
    _input_pins.resize(input_pin_count);
    for (size_t i = 0; i < input_pin_count; ++i)
    {
        _input_pins[i] = new InPin(this, map);
        connect(_input_pins[i], SIGNAL(updateElement()), this, SLOT(updateStatusAllPins()));
        input_layout->addWidget(_input_pins[i]);
    }
    
    _output_pins.resize(_rules.size());
    for (size_t i = 0; i < _rules.size(); ++i)
    {
        _output_pins[i] = new OutPin(this, map, rules[i]);
        output_layout->addWidget(_output_pins[i]);
    }
    
    QWidget *body = new QWidget(this);
    int height_body = (_input_pins.size() > _output_pins.size() ? 
                            _input_pins.size() : 
                            _output_pins.size()) * 30 + 10;
    body->resize(50, height_body);
    body->setStyleSheet("background-color: #ee7dd2;");
    QLabel *label = new QLabel(body);
    QHBoxLayout *l = new QHBoxLayout();
    label->setText(name);
    l->addWidget(label);
    body->setLayout(l);

    layout->addLayout(input_layout);
    layout->addWidget(body);
    layout->addLayout(output_layout);

    this->setLayout(layout);
    
}

/*
QString Element::getRuleByNumberPin(size_t number)
{
    if (number >= _rules.size())
        return "*"; ///error!!!

    return _rules[number];
}
*/


IElement* Element::copy()
{
    return new Element(_map, _input_pins.size(), _rules, _name, qobject_cast<QWidget*>(this->parent()));
}
