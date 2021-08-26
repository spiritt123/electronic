//#pragma once
#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <iostream>
#include <string>
#include <vector>

#include "pin.h"

class Element
{
public:
    Element(size_t input_pin_count = 2, std::string rule = "ab");

    bool getStatus();
    std::string getRule();

private:
    void updateStatus();
    bool isCorrectLetterInRule();

protected:
    bool _status;
    std::string _rule;
    std::vector<Pin*> _input_pins;
    Pin *_output;
};

#endif
