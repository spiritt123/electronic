#pragma once

#include <vector>
//#include "input_pin_menu.h"
#include "pin_menu.h"
//#include "element.h"
#include "pin.h"

#include <QMainWindow>

namespace Ui
{
    class Window;
} // namespace

class Window : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window(QMainWindow *parent = 0, size_t height = 640, size_t width = 480);
    virtual ~Window();

public slots:
    void wire(Pin *pin);
    void on_AddOutputPin_clicked();
    void on_AddInputPin_clicked();
    void on_RemoveOutputPin_clicked();
    void on_RemoveInputPin_clicked();

private:
    size_t _height, _width;
    
    //InputPinMenu *_in_menu;
    PinMenu *_out_menu;
    //std::vector<Element*> _elements;

    Ui::Window *ui;
};

