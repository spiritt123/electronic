#include "ielement.h"
#include <QDebug>
#include "map.h"

IElement::IElement(Map *map, size_t input_pin_count, std::vector<QString> rules, QWidget *parent) : 
    QWidget(parent),
    _map(map),
    _rules(rules)
{
}

void IElement::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        _position = e->globalPos();
    }
}

void IElement::mouseMoveEvent(QMouseEvent *e)
{
    if (_position == QPoint(0, 0))
    {
        _position = e->globalPos();
    }
    QPoint dt = QPoint(_position - e->globalPos());
    this->move(this->pos() - dt);
    //this->move(this->parentWidget()->mapFromGlobal(QCursor::pos()));

    _position = e->globalPos();
    _map->redraw();
}

bool IElement::getStatusOutpuPinByNumber(size_t number)
{
    if (number >= _output_pins.size())
    {
        std::cerr << "Out of range!!!\n";
        return false; 
    }
    updateStatusAllPins();
    return _output_pins[number]->getStatus();
}

size_t IElement::getCountInputPins()
{
    return _input_pins.size();
}

size_t IElement::getCountOutputPins()
{
    return _output_pins.size();
}

/*
QString IElement::getRuleByNumberPin(size_t number)
{
    if (number >= _rules.size())
        return "*"; ///error!!!

    return _rules[number];
}
*/

std::vector<QString> IElement::getRules()
{
    return _rules;
}

void IElement::updateStatusAllPins()
{
    for (auto pin : _output_pins)
    {
        pin->updateStatus(_input_pins);
    }
}
