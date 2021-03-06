#pragma once

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QTextStream>

#include <vector>

#include "element_menu.h"
#include "map.h"
#include "input.h"
#include "output.h"
#include "creator_new_elements.h"
#include "loadStyle.h"

namespace Ui
{
    class Window;
} // namespace

class Window : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window(QMainWindow *parent = 0, QString path = "./settings.txt");
    virtual ~Window();

public slots:
    void on_AddOutputPin_clicked();
    void on_AddInputPin_clicked();
    void on_CreateNewElement_clicked();

private:
    ElementMenu *_element_menu;
    Map *_map;

    std::vector<Input*> _inputs;
    std::vector<Output*> _outputs;

    CreatorNewElements *_creator_new_elements;

    Ui::Window *ui;
};

