#include "menu.h"
#include "ui_settings.h"
#include "window.h"

#include <QDebug>

Settings::Settings(QMainWindow *parent, QString path) : 
    QMainWindow(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_Back_button_clicked()
{
    emit close();
}

