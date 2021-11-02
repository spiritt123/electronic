#pragma once

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QPoint>
#include <QMouseEvent>

#include <vector>
#include <iostream>
#include <string>

#include "ipin.h"
#include "inpin.h"
#include "outpin.h"

//#include "map.h"

class Map;

class IElement : public QWidget
{
    Q_OBJECT
public:
    explicit IElement(Map *map, size_t input_pin_count, std::vector<QString> rules, QWidget *parent = 0);

    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);

    bool getStatusOutpuPinByNumber(size_t number);
    size_t getCountInputPins();
    size_t getCountOutputPins();
    QString getRuleByNumberPin(size_t number);
    std::vector<QString> getRules();

    virtual IElement* copy() = 0;

public slots:
    void updateStatusAllPins();

protected:
    Map *_map;
    std::vector<InPin*> _input_pins;
    std::vector<QString> _rules;
    std::vector<OutPin*> _output_pins;
    QPoint _position;
};
