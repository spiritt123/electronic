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
    Input *input = new Input(_map, ui->Items_field);
    input->show();
}

void Window::on_AddOutputPin_clicked()
{
    Output *output = new Output(_map, ui->Items_field);
    output->show();
}


