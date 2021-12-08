#pragma once

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QTextStream>
#include "loadStyle.h"

#include <vector>

namespace Ui
{
    class Settings;
} // namespace

class Settings : public QMainWindow
{
    Q_OBJECT
public:
    explicit Settings(QMainWindow *parent = 0, QString path = "./settings.txt");
    virtual ~Settings();
    void initSettingsMune();

public slots:
    void on_Back_button_clicked();
    void on_Save_button_clicked();

private:
    QString _path;
    Ui::Settings *ui;
};
