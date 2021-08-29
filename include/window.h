#pragma once

#include <vector>
#include "pin.h"
#include "pin_menu.h"
#include "input_pin_menu.h"
#include "element_menu.h"
#include "wire.h"

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QTextStream>

namespace Ui
{
    class Window;
} // namespace

class Window : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window(QMainWindow *parent = 0, size_t width = 640, size_t height = 480);
    virtual ~Window();

public slots:
    void on_AddOutputPin_clicked();
    void on_AddInputPin_clicked();
    void on_RemoveOutputPin_clicked();
    void on_RemoveInputPin_clicked();

private:
    QString loadStyle(QString path);

private:
    InputPinMenu *_in_menu;
    PinMenu *_out_menu;
    ElementMune *_element_menu;
    Wire *_wire;

    Ui::Window *ui;
};

