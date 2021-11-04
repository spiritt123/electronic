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

QString IElement::getRuleForNewElement(OutPin *out)
{
    std::string rule = out->getRule().toStdString();
    
    std::map<char, QString> dictionary;
    for (int i = 0; i < _input_pins.size(); ++i)
    {
        dictionary['a' + i] = _input_pins[i]->getRuleForNewElement();
    }
    
    std::string final_rule;
    for (int i = 0; i < rule.size(); ++i)
    {
        if (dictionary.find(rule[i]) != dictionary.end())
        {
            final_rule += "(";
            final_rule += dictionary[rule[i]].toStdString();
            final_rule += ")";
        }
        else
        {
            final_rule += rule[i];
        }
    }
    
    return QString(final_rule.c_str());
}
