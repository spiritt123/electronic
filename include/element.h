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

#include "ielement.h"
#include "map.h"
#include "inpin.h"
#include "outpin.h"

class Element : public IElement
{
    Q_OBJECT
public:
    explicit Element(Map *map, size_t input_pin_count, std::vector<QString> rules, QString name = "", QWidget *parent = 0);

    virtual IElement* copy() override;

//public slots:
//    void updateStatusAllPins();

protected:
    QString _name;
};
