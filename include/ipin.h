#pragma once

#include <QPushButton>

class Map;

class IPin : public QPushButton
{
    Q_OBJECT
public:
    explicit IPin(Map *map, QWidget *parent);
    ~IPin() {}
public:
    bool getStatus();

    virtual void setStatus(bool status) = 0;
    virtual QString getName() = 0;
    //virtual void connectPin(IPin* neighbour) = 0;
    //virtual void disconnectPin(IPin* neighbour) = 0;

signals:
    void click(IPin* pin);
    void updateElement();

protected slots:
    void getPointPin();
    bool changeStatus();

protected:
    bool _status;
    Map *_map;
};

