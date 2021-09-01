#pragma once

#include <QWidget>
#include <QVBoxLayout>

#include <vector>

#include "pin.h"
#include "wire.h"

class PinMenu : public QWidget
{
    Q_OBJECT
public:
    PinMenu(QWidget *parent = 0, QVBoxLayout *layout = 0, Wire *wire = nullptr, pin_types pins_type = output_pin, size_t limit = 10);

    ~PinMenu();

    void setRadiusPin(double radius);
    void addPin();
    void removePin();

    Pin* getPinForNumber(size_t number);

    size_t getLimit();
    void setLimit(size_t limit);

protected:
    size_t _count, _limit;
    double _radius;
    pin_types _pins_type;
    QVBoxLayout *_layout;
    Wire *_wire;
};
