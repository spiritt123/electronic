#pragma once

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QTextStream>

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

public slots:
    //void on_Start_button_clicked();
    //void on_Settings_button_clicked();

//private:
//    QString loadStyle(QString path);

private:
    Ui::Settings *ui;
};
