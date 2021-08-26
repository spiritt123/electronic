#pragma once

#include <vector>
#include <QWidget>
#include <QVBoxLayout>
#include "pin.h"

class PinMenu : public QWidget
{
    Q_OBJECT
public:
    PinMenu(QWidget *parent = 0, pin_types pins_type = output_pin, 
            int x = 0, int y = 0, int len = 50, size_t limit = 10);

    ~PinMenu();

    void setLayout(QVBoxLayout *parent)
    {
        _parent = parent;
    };
 
    void setRadiusPin(double radius);
    void addPin();
    void removePin();

    Pin* getPinForNumber(size_t number);

    size_t getLimit();
    void setLimit(size_t limit);

protected:
    size_t _count, _limit;
    int _x, _y, _len;
    double _radius;
    pin_types _pins_type;
    QVBoxLayout *_parent;
};
