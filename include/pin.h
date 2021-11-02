#pragma once

#include <QPushButton>
#include <QString>

#include <iostream>

class Wire;

enum pin_types
{
    input_pin,
    output_pin
};

class Pin : public QPushButton
{
    Q_OBJECT
public:
    Pin(QWidget *parent, 
        Wire *wire, 
        QString rule = "0",
        pin_types pin_type = input_pin, 
        bool status = false, 
        Pin *neighbour = nullptr);
    ~Pin();

    void setStatus(bool status);
    void setNeighbour(Pin *neighbour);
    void setPinType(pin_types pin_type);

    bool  getStatus();
    Pin*  getNeighbour();
    pin_types getPinType();

    void connectPin(Pin* neighbour);
    void disconnectPin(Pin* neighbour);

    void setRule(QString rule);
    QString getRule();
    void clearOutPath();

    void updateStatus(std::vector<Pin*> input_pins);

signals:
    void click(Pin* pin);
    void updateElement();

private slots:
    void getPointPin();
    bool changeStatus();

private:
    bool isCorrectLetterInRule(int count_input_pins);

private:
    bool _status;
    pin_types _pin_type;
    Pin* _neighbour;
    QString _rule;
};

