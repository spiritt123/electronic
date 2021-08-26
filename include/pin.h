#pragma once

#include <QPushButton>

enum pin_types
{
    input_pin,
    output_pin
};

class Pin : public QPushButton
{
    Q_OBJECT
public:
    Pin(QWidget *parent, pin_types pin_type = input_pin, bool status = false, Pin *neighbour = nullptr);
    ~Pin();

    bool changeStatus();

    void setStatus(bool status);
    void setNeighbour(Pin *neighbour);
    void setPinType(pin_types pin_type);

    bool  getStatus();
    Pin*  getNeighbour();
    pin_types getPinType();

    void connectPin(Pin* neighbour);
    void disconnectPin(Pin* neighbour);

signals:
    void click(Pin* pin);

private slots:
    void getPointPin();

private:
    bool _status;
    pin_types _pin_type;
    Pin* _neighbour;
};

