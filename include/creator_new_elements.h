#pragma once

#include <vector>

#include <QString>

#include "element.h"
#include "input.h"
#include "output.h"

class CreatorNewElements
{
public:
    CreatorNewElements(std::vector<Input*> *inputs, std::vector<Output*> *outputs);
    ~CreatorNewElements();
    
    Element* create(QString name);

private:
    std::vector<Input*> *_inputs;
    std::vector<Output*> *_outputs;
};
