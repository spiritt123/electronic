#pragma once

#include <QString>

#include "ipin.h"

class InPin;
class Map;

class OutPin : public IPin
{
public:
    OutPin(QWidget *parent, Map *map, QString rule);
    ~OutPin();

    void setNeighbour(InPin *neighbour);
    InPin*  getNeighbour();

    void connectPin(InPin* neighbour);
    void disconnectPin(InPin* neighbour);

    void updateStatus(std::vector<InPin*> input_pins);

    virtual void setStatus(bool status) override;
    virtual QString getName() override {return "outpin";}

private:
    bool isCorrectLetterInRule(int count_input_pins);

private:
    InPin* _neighbour;
    QString _rule;
};


