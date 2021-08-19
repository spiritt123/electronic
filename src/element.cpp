#include "element.h"

Element::Element(size_t input_pin_count, std::string rule)
{
    _rule = rule;
    _status = false;
    _input_pins.resize(input_pin_count);
    for (size_t i = 0; i < input_pin_count; ++i)
    {
        _input_pins[i] = Pin(this);
    }
    _output = Pin(this);
}

bool Element::getStatus()
{
    updateStatus();
    return _status;
}

std::string Element::getRule()
{
    return _rule;
}

void Element::updateStatus()
{
    if (!isCorrectLetterInRule())
    {
        std::cerr << "invalid characters in rule\n";
        _status = false;
        return ;
    }
    
    bool result = true;
    for (size_t i = 0; i < _rule.size(); ++i)
    {
        if (_rule[i] == '+')
        {
            if (result == true)
            {
                _status = true;
                return ;
            }
            else
            {
                result == true;
                continue;
            }
        }
        else if (_rule[i] == '!')
        {
            result &= !_input_pins[_rule[++i] - 'a'].getStatus();
        }
        else
        {
            result &= _input_pins[_rule[i] - 'a'].getStatus();
        }
    }
    _status = result;
}

bool Element::isCorrectLetterInRule()
{
    int table[3][3] = 
    {
//      !  c  +
/*0*/   1, 2, 9,
/*1*/   9, 2, 9,
/*2*/   1, 2, 0
    };
    int state = 0;

    for (size_t i = 0; i < _rule.size(); ++i)
    {
        if (_rule[i] == '+') 
            state = table[state][2];
        else if (_rule[i] == '!')
            state = table[state][0];
        else if (_rule[i] >= 'a' && _rule[i] < 'a' + _input_pins.size())
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

