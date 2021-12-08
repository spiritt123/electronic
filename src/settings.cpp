#include "menu.h"
#include "ui_settings.h"
#include "window.h"

#include <QDebug>


Settings::Settings(QMainWindow *parent, QString path) : 
    QMainWindow(parent),
    _path(path),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

    setStyleSheet(loadStyle("css/style.css"));
    setStyleSheet(loadStyle("css/background.css"));
    initSettingsMune();
}

Settings::~Settings()
{
    delete ui;
}

void Settings::initSettingsMune()
{
    QString data;
    QFile file(_path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return ;

    int i = 0;
    QString cbutton, cbackground; 
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        data += line + "\n";
        ++i;
        switch (i)
        {
        case 3:
            cbackground = (line.right(8)).left(7);
            break;
        case 4:
            break;
        case 5:
            break;
        case 10:
            cbutton = (line.right(8)).left(7);
            break;
        }
    }
    file.close();

    ui->line_color_background->setText(cbackground);
    ui->line_color_button->setText(cbutton);
}

void Settings::on_Back_button_clicked()
{
    emit close();
}

void Settings::on_Save_button_clicked()
{
    QString rule = "";
    rule += "QMainWindow\n";
    rule += "{\n";
    rule += "    baCkground-color: " + ui->line_color_background->text() + ";\n";
    QString screen_size = ui->Screen_range->currentText();
    rule += "    min-width: " + screen_size.left(screen_size.indexOf('x')) + "px;\n";
    rule += "    min-height: " + screen_size.right(screen_size.indexOf('x')) + "px;\n";
    rule += "}\n";
    rule += "\n";
    rule += "QPushButton\n";
    rule += "{\n";
    rule += "    background-color:" + ui->line_color_button->text() +";\n";
    rule += "}\n";
    
    QFile file(_path);    
    if (file.open(QIODevice::ReadWrite)) 
    {        
        QTextStream stream(&file);        
        stream << rule << endl;    
    }
    file.close();
}


/*
 *
    baCkground-color: #535c70;\n";
    min-width: 300px;\n";
    min-height: 300px;\n";
 *
 *button #61f22c 
 */
