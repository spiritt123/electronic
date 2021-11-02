#include "element_menu.h"
#include "input.h"
#include <QDebug>

ElementMenu::ElementMenu(QWidget *parant, QHBoxLayout *layout, Map *map) : 
    QWidget(parant),
    _layout(layout),
    _map(map)
{
    createStartElements();

}

ElementMenu::~ElementMenu() {}

void ElementMenu::loadNewElementFormFile(QString path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return ;

    QTextStream in(&file);
    while (!in.atEnd())
    {
        int in_pin, out_pin;
        QString name;
        
        QString line = in.readLine();
        in_pin = line.split(" ")[0].toInt();
        out_pin = line.split(" ")[1].toInt();
        name = line.split(" ")[2];

        std::vector<QString> rules;
        rules.resize(out_pin);
        //in out \ lines
        for (int i = 0; !in.atEnd() && i < out_pin; ++i)
        {
            rules[i] = in.readLine();
        }

        Element *new_element = new Element(_map, in_pin, rules, name, this);
        addNewElement(new_element, name);
    }
}

void ElementMenu::addNewElement(IElement *element, QString name_element)
{
    NewElementButton *element_button = new NewElementButton(static_cast<IElement*>(element), name_element, this);
    connect(element_button, SIGNAL(click(IElement*)), _map, SLOT(addElement(IElement*)));

    _layout->insertWidget(_layout->count() - 1, element_button);
    element->hide();
    //_elements.push_back(element);
}

void ElementMenu::saveAllElementInFile(QString path)
{
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return ;

    for (int i = 2; 
            QString(_layout->itemAt(i)->widget()->metaObject()->className()) 
                == "QPushButton" &&
            i < _layout->count(); 
        ++i)
    {
        std::vector<QString> outputs = _elements[i]->getRules();
        size_t input_count = _elements[i]->getCountInputPins();
        size_t output_count = outputs.size();
        QString name = qobject_cast<QPushButton*>(_layout->itemAt(i)->widget())->text();

        QString line;
        line += QString::number(input_count) + " " + QString::number(output_count);
        line += " " + name + "\n";
        file.write(line.toLocal8Bit().data());
        for (size_t i = 0; i < output_count; ++i)
        {
            QString str = outputs[i] + "\n";
            file.write(str.toLocal8Bit().data());
        }
    }
}

void ElementMenu::createStartElements()
{
    addNewElement(new Element(_map, 2, {"ab"}, "and", qobject_cast<QWidget*>(_map->parent())), "and");
    addNewElement(new Element(_map, 1, {"!a"}, "not", qobject_cast<QWidget*>(_map->parent())), "not");
}    
 
