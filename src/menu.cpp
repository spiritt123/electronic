#include "menu.h"
#include "ui_menu.h"
#include <thread>

#include <QDebug>

Menu::Menu(QMainWindow *parent) : 
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);

    _window = nullptr;
    _settings = new Settings(0, "./css/background.css");

    setStyleSheet(loadStyle("css/style.css"));
    setStyleSheet(loadStyle("css/background.css"));
}

Menu::~Menu()
{
    delete ui;
}

    
void Menu::on_Start_button_clicked()
{
    if (_window == nullptr)
    {
        _window = new Window(0, "./settings.txt");
        _window->show();
        emit close();
    }
}

/*
void StartSettings()
{
    Settings *settings = new Settings(0, "./settings.txt");
    settings->show();
}
*/

void Menu::on_Settings_button_clicked()
{
    if (!_settings->isVisible())
    {
        _settings->show();
    }
}
