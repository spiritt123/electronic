#include "map.h"
#include <QObject>
#include <QDebug>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

Map::Map(QWidget *perant) :
    QWidget(perant)
{
    resize(800, 800);
    connect(this, SIGNAL(drawWire(QPoint, QPoint)), this, SLOT( set(QPoint, QPoint) ) );
}

Map::~Map()
{
    _wires.clear();
}

void Map::addElement(IElement *element, int x, int y)
{
    element->move(x, y);
    element->show();
}

void Map::set(QPoint first, QPoint second) 
{
    //_wires.push_back(std::make_pair(first, second));
    this->update();
};

void Map::redraw()
{
    update();
}

void Map::paintEvent(QPaintEvent *event)
{
     //_painter = new QPainter(qobject_cast<QWidget*>(this->parent()));
    _painter = new QPainter(this);
    _painter->setPen(QPen(Qt::black, 12, Qt::SolidLine, Qt::RoundCap));
    for (int i = 0; i < _wires.size(); ++i)
    {
        auto start = qobject_cast<QWidget*>(_wires[i].first->parent())->geometry();
        auto end   = qobject_cast<QWidget*>(_wires[i].second->parent())->geometry();
        _painter->drawLine(
            QPoint(start.x(), start.y()) + _wires[i].first->pos() + QPoint(15, 15),
            QPoint(end.x(), end.y()) + _wires[i].second->pos() + QPoint(15, 15)
        );
    }
    
    delete _painter;
};


void Map::createWire(IPin *pin)
{
    static InPin   *in = nullptr;
    static OutPin *out = nullptr;

    if (pin->getName() == "inpin")
    {
        in = static_cast<InPin*>(pin);
    }

    if (pin->getName() == "outpin")
    {
        out = static_cast<OutPin*>(pin);
    }

    if (in == nullptr || out == nullptr)
    {
        return;
    }

    in->disconnectPin(in->getNeighbour());
    out->disconnectPin(out->getNeighbour());
    removeWire(in);
    removeWire(out);

    in->connectPin(out);
    out->connectPin(in);

    _wires.push_back(std::make_pair(in, out));

    in = nullptr;
    out = nullptr;

    update();
}

void Map::removeWire(IPin *pin)
{
    for (auto iter = _wires.begin(); iter != _wires.end(); ++iter)
    {
        if (pin == iter->first || pin == iter->second)
        {
            _wires.erase(iter);
            return;
        }
    }
}

