#pragma once

#include <vector>

#include <QString>

#include "element.h"
#include "input.h"
#include "output.h"

class Map;

class CreatorNewElements
{
public:
    CreatorNewElements(Map *map, std::vector<Input*> *inputs, std::vector<Output*> *outputs);
    ~CreatorNewElements();
    
    Element* create(QString name);

private:
    Map *_map;
    std::vector<Input*> *_inputs;
    std::vector<Output*> *_outputs;
};
