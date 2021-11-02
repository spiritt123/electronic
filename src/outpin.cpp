#include "outpin.h"
#include "inpin.h" 
#include "map.h"

#include <iostream>
#include <QDebug>

OutPin::OutPin(QWidget *parent, Map *map, QString rule)
    : IPin(map, parent),
    _rule(rule)
{
    _neighbour = nullptr;

    this->setObjectName("outpin");
    this->setStyleSheet("background-color: black");
}

OutPin::~OutPin()
{
    if (_neighbour != nullptr)
        disconnectPin(_neighbour);
}

void OutPin::setNeighbour(InPin *neighbour)
{
    _neighbour = neighbour;
}

InPin* OutPin::getNeighbour()
{
    return _neighbour;
}

void OutPin::connectPin(InPin* neighbour)
{
    if (_neighbour != nullptr)
    {
        disconnectPin(_neighbour);
    }
    
    _neighbour = neighbour;
    
    // Получение нового сигнала после подключения.
    setStatus(neighbour->getStatus());
}

void OutPin::updateStatus(std::vector<InPin*> input_pins)
{
    if (!isCorrectLetterInRule(input_pins.size()))
    {
        std::cerr << "invalid characters in rule\n";
        setStatus(false);
        return ;
    }
    //.toAscii();
    bool result = true;
    for (size_t j = 0; j < _rule.length(); ++j)
    {
        if (_rule.at(j).unicode() == '+')
        {
            if (result == true)
            {
                setStatus(true);
                return ;
            }
            else
            {
                result = true;
                continue;
            }
        }
        else if (_rule.at(j).unicode() == '!')
        {
            result &= !input_pins[_rule.at(++j).unicode() - 'a']->getStatus();
        }
        else
        {
            result &= input_pins[_rule.at(j).unicode() - 'a']->getStatus();
        }
    }
    //    qDebug() << result;
    setStatus(result);
}

bool OutPin::isCorrectLetterInRule(int count_input_pins)
{
    int table[3][3] = 
    {
//      !  c  +
/*0*/   1, 2, 9,
/*1*/   9, 2, 9,
/*2*/   1, 2, 0
    };
    int state = 0;

    for (size_t i = 0; i < _rule.count(); ++i)
    {
        if (_rule.at(i) == '+') 
            state = table[state][2];
        else if (_rule.at(i) == '!')
            state = table[state][0];
        else if (_rule.at(i) >= 'a' && 
                 _rule.at(i).unicode() <  'a' + count_input_pins)
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
void OutPin::disconnectPin(InPin* neighbour)
{
    if (_neighbour == nullptr)
        return ;

    if (neighbour != _neighbour)
        return ;
    
    InPin *buffer = _neighbour;
    _neighbour = nullptr;
    buffer->disconnectPin(this);
}

void OutPin::setStatus(bool status)
{
    _status = status;
    if (_status == true)
        this->setStyleSheet("background-color: red");
    else
        this->setStyleSheet("background-color: black");

    //qDebug() << (_neighbour == nullptr);
    if (_neighbour != nullptr)
    {
        _neighbour->setStatus(_status);
    }
    emit updateElement();
}
