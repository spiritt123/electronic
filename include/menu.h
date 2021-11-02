#pragma once

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QTextStream>

#include <vector>
#include "window.h"
#include "settings.h"

namespace Ui
{
    class Menu;
} // namespace

class Menu : public QMainWindow
{
    Q_OBJECT
public:
    explicit Menu(QMainWindow *parent = 0);
    virtual ~Menu();

public slots:
    void on_Start_button_clicked();
    void on_Settings_button_clicked();

//private:
//    QString loadStyle(QString path);

private:
    Window *_window;
    Settings *_settings;

private:
    Ui::Menu *ui;
};

