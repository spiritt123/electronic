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

private:
    QString loadStyle(QString path);

private:
    ElementMenu *_element_menu;
    Map *_map;

    std::vector<Input*> _inputs;
    std::vector<Output*> _outputs;

    Ui::Window *ui;
};

