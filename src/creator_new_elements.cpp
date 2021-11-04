#include "creator_new_elements.h"

#include <QDebug>

CreatorNewElements::CreatorNewElements(
    std::vector<Input*> *inputs,
    std::vector<Output*> *outputs
        ):
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
        qDebug() << rules[i];
    }

    return nullptr;
    //return new Element(input_count, rules, name);
}

