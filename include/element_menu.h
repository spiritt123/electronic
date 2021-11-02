#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFile>
#include <QTextStream>

#include "element.h"
#include "map.h"
#include "new_element_button.h"
#include "input.h"

class ElementMenu : public QWidget
{
    Q_OBJECT
public:
    ElementMenu(QWidget *parant, QHBoxLayout *layout, Map *map);
    ~ElementMenu();

    void loadNewElementFormFile(QString path);
    void addNewElement(IElement *element, QString name_element);
    void saveAllElementInFile(QString path);

private:
    void createStartElements();
    
private:
    QHBoxLayout *_layout;
    std::vector<Element*> _elements;
    Map *_map;
};

