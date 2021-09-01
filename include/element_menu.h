#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFile>
#include <QTextStream>

#include "element.h"
#include "wire.h"
#include "map.h"
#include "pin.h"
#include "new_element_button.h"

class ElementMune : public QWidget
{
    Q_OBJECT
public:
    ElementMune(QWidget *parant, QHBoxLayout *layout, Wire *wire, Map *map);
    ~ElementMune();

    void loadNewElementFormFile(QString path);
    void addNewElement(Element *element, QString name_element);
    void saveAllElementInFile(QString path);

private:
    void createStartElements();
    
private:
    QHBoxLayout *_layout;
    std::vector<Element*> _elements;
    Wire *_wire;
    Map *_map;
};

