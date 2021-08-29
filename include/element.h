#pragma once

#include <QWidget>

#include <vector>
#include <iostream>
#include <string>

#include "pin.h"
#include "wire.h"

class Element : public QWidget
{
    Q_OBJECT
public:
    explicit Element(Wire *wire, size_t input_pin_count, std::vector<QString> rules, QWidget *parent = 0);

    bool getStatusOutpuPinByNumber(size_t number);
    size_t getCountInputPins();
    size_t getCountOutputPins();
    QString getRuleByNumberPin(size_t number);
    std::vector<QString> getRules();

public slots:
    void updateStatus();

private:
    bool isCorrectLetterInRule(size_t number);

protected:
    std::vector<QString> _rules;
    std::vector<Pin*> _input_pins;
    std::vector<Pin*> _output_pins;
};
