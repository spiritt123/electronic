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
{}

void Map::addElement(IElement *element, int x, int y)
{
    element->move(x, y);
    element->show();
}

void Map::set(QPoint first, QPoint second) 
{
    //_wires.push_back(std::make_pair(first, second));
    update();
};


void Map::paintEvent(QPaintEvent *event)
{
     //_painter = new QPainter(qobject_cast<QWidget*>(this->parent()));
    _painter = new QPainter(this);
    _painter->setPen(QPen(Qt::black, 12, Qt::SolidLine, Qt::RoundCap));
    //for (const auto* wire : _wires)
    for (int i = 0; i < _wires.size(); ++i)
    {
        _painter->drawLine(
            QPoint(
                qobject_cast<QWidget*>(_wires[i].first->parent())->geometry().x(),
                qobject_cast<QWidget*>(_wires[i].first->parent())->geometry().y()
            ) + _wires[i].first->pos() + QPoint(15, 15),
            QPoint(
                qobject_cast<QWidget*>(_wires[i].second->parent())->geometry().x(),
                qobject_cast<QWidget*>(_wires[i].second->parent())->geometry().y()
            ) + _wires[i].second->pos() + QPoint(15, 15)
        );
        
    }
    
    /*
    qDebug() << qobject_cast<QWidget*>(first)->pos();
    qDebug() << qobject_cast<QWidget*>(first->parent())->pos();
    qDebug() << "==================================";
    */
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

    in->connectPin(out);
    out->connectPin(in);

    _wires.push_back(std::make_pair(in, out));

    in = nullptr;
    out = nullptr;
    update();

    //qDebug() << "!!!!!! " <<  pin->getName();

    /*if (sizeof(qobject_cast<QWidget*>(first->parent()) ) == sizeof(new InputPinMenu(nullptr, nullptr, nullptr)))
    {
        emit _map->drawWire(
            QPoint(-15, qobject_cast<QWidget*>(first)->y() -15),
            qobject_cast<QWidget*>(second->parent())->pos() + second->pos() + QPoint(15, 15)
            );
    }
    
    if (sizeof(qobject_cast<QWidget*>(second->parent()) ) == sizeof(new PinMenu(nullptr, nullptr, nullptr)))
    {
        emit _map->drawWire(
            qobject_cast<QWidget*>(second->parent())->pos() + second->pos() + QPoint(15, 15),
            QPoint(qobject_cast<QWidget*>(first)->y() -15, qobject_cast<QWidget*>(first)->y() -15)
            );
    }*/

}
