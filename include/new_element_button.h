#pragma once

#include <QPushButton>
#include <QWidget>

#include "element.h"
#include "ielement.h"

class NewElementButton : public QPushButton
{
    Q_OBJECT
public:
    NewElementButton(IElement *element, QString name, QWidget *parent);
    ~NewElementButton();

signals:
    void click(IElement *element);

public slots:
    void addElement();

private:
    IElement *_element;

};


