#include "window.h"
#include "ui_mainwindow.h"
#include "input.h"
#include "output.h"
#include <QDebug>

Window::Window(QMainWindow *parent, QString path) : 
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

    setStyleSheet(loadStyle("css/style.css"));

    this->resize(800, 600);

    _map = new Map(ui->Items_field);

    _element_menu = new ElementMenu(ui->ListElements, ui->ListElementsLayout, _map);

    _creator_new_elements = new CreatorNewElements(&_inputs, &_outputs);
}

Window::~Window()
{
    delete ui;
}

QString Window::loadStyle(QString path)
{
    QString data;
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return "";

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        data += line + "\n";
    }
    return data;
}
   
void Window::on_AddInputPin_clicked()
{
    static int x = 10;
    static int y = 10;
    QString rule = "";
    char ch = 'a' + _inputs.size();
    Input *input = new Input(_map, ui->Items_field, rule += ch);
    _inputs.push_back(input);
    _map->addElement(input, x, y);
    y += 30;
}

void Window::on_AddOutputPin_clicked()
{
    static int x = 700;
    static int y = 10;
    Output *output = new Output(_map, ui->Items_field);
    _outputs.push_back(output);
    _map->addElement(output, x, y);
    y += 30;
}

void Window::on_CreateNewElement_clicked()
{
    auto new_element = _creator_new_elements->create(ui->NewNameElement->text());
    // add element to panel
}
