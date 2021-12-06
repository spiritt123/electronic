#include "creator_new_elements.h"
#include "map.h"
#include <QDebug>

CreatorNewElements::CreatorNewElements(
    Map *map,
    std::vector<Input*> *inputs,
    std::vector<Output*> *outputs
        ):
    _map(map),
    _inputs(inputs),
    _outputs(outputs)
{}

CreatorNewElements::~CreatorNewElements() {}


Element* CreatorNewElements::create(QString name)
{
    int input_count = _inputs->size();
    int output_count = _outputs->size();

    std::vector<QString> rules;
    rules.resize(output_count);

    for (int i = 0; i < output_count; ++i)
    {
        rules[i] = _outputs->at(i)->getRuleForNewElement();
       // qDebug() << rules[i];
    }

    //return nullptr;
    return new Element(_map, input_count, rules, name, qobject_cast<QWidget*>(_map->parent()));
}

