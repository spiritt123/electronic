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

bool OutPin::getNewStatus(std::string &rule, std::vector<InPin*> input_pins)
{
    bool result = true;
    while (rule.size() > 0)
    {
        if (rule[0] == '+')
        {
            if (result == true)
            {
                setStatus(true);
                rule = "";
                return true;
            }
            else
            {
                result = true;
                continue;
            }
        }
        else if (rule[0] == '(')
        {
            rule.erase(0, 1);
            result &= getNewStatus(rule, input_pins);
        }
        else if (rule[0] == ')')
        {
            rule.erase(0, 1);
            return result;
        }
        else if (rule[0] == '!')
        {
            rule.erase(0, 1);
            result &= ! getNewStatus(rule, input_pins);
        }
        else
        {
            result &= input_pins[rule[0] - 'a']->getStatus();
        }
        rule.erase(0, 1);
    }
    return result;
}


void OutPin::updateStatus(std::vector<InPin*> input_pins)
{
    if (!isCorrectLetterInRule(input_pins.size()))
    {
        std::cerr << "invalid characters in rule\n";
        setStatus(false);
        return ;
    }

    std::string rule = _rule.toStdString();
    setStatus(getNewStatus(rule, input_pins));
}

static bool isCorrect(std::string rule, int count_outputs);

bool OutPin::isCorrectLetterInRule(int count_input_pins)
{
    return isCorrect(_rule.toStdString(), count_input_pins);
}

static bool isCorrect(std::string rule, int count_outputs)
{
    int table[3][3] = 
    {
//      !  c  +
/*0*/   1, 2, 9,
/*1*/   1, 2, 9,
/*2*/   1, 2, 0
    };
    int state = 0;

//    qDebug() << ">>1 " << QString(rule.c_str());
    while (rule.size() > 0)
    {
        if (rule[0] == '+') 
            state = table[state][2];
        else if (rule[0] == '!')
            state = table[state][0];
        else if (rule[0] >= 'a' && 
                 rule[0] <  'a' + count_outputs)
            state = table[state][1];
        else if (rule[0] == '(')
        {
            rule.erase(0, 1);
            if (isCorrect(rule, count_outputs) == false)
                return false;
            state = 2;
            rule.erase(0, rule.find_first_of(")") + 1);
        }
        else if (rule[0] == ')')
        {
            if (state == 2) return true;
            return false;
        }
        else
            return false;
        rule.erase(0, 1);

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

    if (_neighbour != nullptr)
    {
        _neighbour->setStatus(_status);
    }
    emit updateElement();
}

QString OutPin::getRuleForNewElement()
{
    return static_cast<IElement*>(this->parent())->getRuleForNewElement(this);
}

QString OutPin::getRule()
{
    return _rule;
}



