#include "map.h"
#include <QDebug>

Map::Map(QWidget *perant) :
    QWidget(perant)
{
}

Map::~Map()
{}

void Map::addElement(Element *element, int x, int y)
{
    element->move(x, y);
    element->show();
    //_elements.push_back(element);
}
