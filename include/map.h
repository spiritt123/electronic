#pragma once

#include <QWidget>
#include "element.h"

class Map : public QWidget
{
    Q_OBJECT
public:
    Map(QWidget *parent);
    ~Map();

public slots:
    void addElement(Element *element, int x = 10, int y = 10);
    
private:
};
