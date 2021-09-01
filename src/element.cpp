#include "element.h"
#include <QDebug>

Element::Element(Wire *wire, size_t input_pin_count, std::vector<QString> rules, QString name, QWidget *parent) : 
    QWidget(parent),
    _wire(wire),
    _rules(rules),
    _name(name)
{
    QHBoxLayout *layout = new QHBoxLayout();
    QVBoxLayout *input_layout = new QVBoxLayout();
    QVBoxLayout *output_layout = new QVBoxLayout();
    
    _input_pins.resize(input_pin_count);
    for (size_t i = 0; i < input_pin_count; ++i)
    {
        _input_pins[i] = new Pin(this, wire, input_pin);
        connect(_input_pins[i], SIGNAL(updateElement()), this, SLOT(updateStatus()));
        input_layout->addWidget(_input_pins[i]);
    }
    
    _output_pins.resize(_rules.size());
    for (size_t i = 0; i < _rules.size(); ++i)
    {
        _output_pins[i] = new Pin(this, wire, output_pin);
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

void Element::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        _position = e->globalPos();
    }
}

void Element::mouseMoveEvent(QMouseEvent *e)
{
    QPoint dt = QPoint(_position - e->globalPos());
    this->move(this->pos() - dt);

    _position = e->globalPos();
}

bool Element::getStatusOutpuPinByNumber(size_t number)
{
    if (number >= _output_pins.size())
    {
        std::cerr << "Out of range!!!\n";
       return false; 
    }
    updateStatus();
    return _output_pins[number]->getStatus();
}

size_t Element::getCountInputPins()
{
    return _input_pins.size();
}

size_t Element::getCountOutputPins()
{
    return _output_pins.size();
}

QString Element::getRuleByNumberPin(size_t number)
{
    if (number >= _rules.size())
        return "*"; ///error!!!

    return _rules[number];
}

std::vector<QString> Element::getRules()
{
    return _rules;
}

void Element::updateStatus()
{
    for (size_t i = 0; i < _rules.size(); ++i)
    {
        if (!isCorrectLetterInRule(i))
        {
            std::cerr << "invalid characters in rule\n";
            _output_pins[i]->setStatus(false);
            return ;
        }
        //.toAscii();
        bool result = true;
        for (size_t j = 0; j < _rules[i].length(); ++j)
        {
            if (_rules[i].at(j).unicode() == '+')
            {
                if (result == true)
                {
                    _output_pins[i]->setStatus(true);
                    return ;
                }
                else
                {
                    result = true;
                    continue;
                }
            }
            else if (_rules[i].at(j).unicode() == '!')
            {
                result &= !_input_pins[_rules[i].at(++j).unicode() - 'a']->getStatus();
            }
            else
            {
                result &= _input_pins[_rules[i].at(j).unicode() - 'a']->getStatus();
            }
        }
        _output_pins[i]->setStatus(result);
    }
}

bool Element::isCorrectLetterInRule(size_t number)
{
    int table[3][3] = 
    {
//      !  c  +
/*0*/   1, 2, 9,
/*1*/   9, 2, 9,
/*2*/   1, 2, 0
    };
    int state = 0;

    for (size_t i = 0; i < _rules[number].count(); ++i)
    {
        if (_rules[number].at(i) == '+') 
            state = table[state][2];
        else if (_rules[number].at(i) == '!')
            state = table[state][0];
        else if (_rules[number].at(i) >= 'a' && 
                 _rules[number].at(i).unicode() <  'a' +_input_pins.size())
            state = table[state][1];
        else
            return false;

        if (state == 9)
            return false;
    }

    if (state == 2)
        return true;
    return false;
}

Element* Element::copy()
{
    return new Element(_wire, _input_pins.size(), _rules, _name, qobject_cast<QWidget*>(this->parent()));
}
