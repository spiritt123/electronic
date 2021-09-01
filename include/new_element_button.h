#pragma once

#include <QPushButton>
#include <QWidget>

#include "element.h"

class NewElementButton : public QPushButton
{
    Q_OBJECT
public:
    NewElementButton(Element *element, QString name, QWidget *parent);
    ~NewElementButton();

signals:
    void click(Element *element);

public slots:
    void addElement();

private:
    Element *_element;

};


