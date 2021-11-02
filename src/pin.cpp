#include "pin.h"
#include "wire.h"

#include <QDebug>

Pin::Pin(QWidget *parent, Wire *wire, QString rule, pin_types pin_type, bool status, Pin *neighbour) :
    QPushButton(parent),
    _rule(rule),
    _pin_type(pin_type),
    _status(status),
    _neighbour(neighbour)
{
    if (pin_type == input_pin)
        this->setObjectName("inpin");
    else
        this->setObjectName("outpin");
    
    this->setStyleSheet("background-color: black");
    
    connect(this, SIGNAL( clicked() ), this, SLOT( getPointPin() ));
    
    if (wire != nullptr)
        connect(this, SIGNAL( click(Pin*) ), (Wire*)wire, SLOT( createWire(Pin*) ));
}

Pin::~Pin()
{
    if (_neighbour != nullptr)
        disconnectPin(_neighbour);
}

void Pin::getPointPin()
{
    emit click(this);
}

bool Pin::changeStatus()
{
    _status ^= 1;
    
    setStatus(_status);

    return _status;
}

void Pin::setStatus(bool status)
{
    _status = status;

    if (_status == true)
        this->setStyleSheet("background-color: red");
    else
        this->setStyleSheet("background-color: black");

    if (_pin_type == output_pin && _neighbour != nullptr)
        _neighbour->setStatus(_status);
    emit updateElement();
}

void Pin::setNeighbour(Pin *neighbour)
{
    _neighbour = neighbour;
}

void Pin::setPinType(pin_types pin_type)
{
    _pin_type = pin_type;
}

bool Pin::getStatus()
{
    return _status;
}

Pin* Pin::getNeighbour()
{
    return _neighbour;
}

pin_types Pin::getPinType()
{
    return _pin_type;
}

void Pin::connectPin(Pin* neighbour)
{
    if (neighbour->getPinType() == _pin_type || neighbour == nullptr)
        return ;

    _neighbour = neighbour;
    
    // Получение нового сигнала после подключения.
    if (_pin_type == input_pin)
        setStatus(neighbour->getStatus());
}

void Pin::disconnectPin(Pin *neighbour)
{
    if (_neighbour == nullptr)
        return ;

    if (neighbour != _neighbour)
        return ;
    
    Pin *buffer = _neighbour;
    _neighbour = nullptr;
    buffer->disconnectPin(this);

    if (_pin_type == input_pin)
    {
        setStatus(false);
        // перерасчёт сигнала!!!
    }
}


void Pin::setRule(QString rule)
{
    _rule = rule;
}

QString Pin::getRule()
{
    return _rule;
}

void Pin::clearOutPath()
{
    if (_pin_type == input_pin)
    {
        _rule = "";
    }
}

void Pin::updateStatus(std::vector<Pin*> input_pins)
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
        qDebug() << result;
    setStatus(result);
}

bool Pin::isCorrectLetterInRule(int count_input_pins)
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
