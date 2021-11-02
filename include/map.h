#pragma once

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QPoint>
#include "ielement.h"
#include "inpin.h"
#include "outpin.h"
#include "ipin.h"

#include <QDebug>

class Map : public QWidget
{
    Q_OBJECT
public:
    Map(QWidget *parent);
    ~Map();

    void redraw();

signals:
    void drawWire(QPoint, QPoint);

protected:
    void paintEvent(QPaintEvent *event);
    

public slots:
    void addElement(IElement *element, int x = 10, int y = 10);
    void createWire(IPin *pin);
    void removeWire(IPin *pin);
    void set(QPoint first, QPoint second);
    
private:
    QPainter *_painter;
    std::vector<std::pair<InPin*, OutPin*>> _wires;
};
