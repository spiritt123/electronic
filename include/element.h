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

#include "pin.h"
#include "wire.h"

class Element : public QWidget
{
    Q_OBJECT
public:
    explicit Element(Wire *wire, size_t input_pin_count, std::vector<QString> rules, QString name = "", QWidget *parent = 0);

    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);

    bool getStatusOutpuPinByNumber(size_t number);
    size_t getCountInputPins();
    size_t getCountOutputPins();
    QString getRuleByNumberPin(size_t number);
    std::vector<QString> getRules();

    Element* copy();

public slots:
    void updateStatus();

private:
    bool isCorrectLetterInRule(size_t number);

protected:
    Wire *_wire;
    std::vector<QString> _rules;
    std::vector<Pin*> _input_pins;
    std::vector<Pin*> _output_pins;
    QString _name;
    QPoint _position;
};
