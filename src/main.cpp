#include <QApplication>
#include "window.h"
#include "menu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Window w;
    //w.show();
    //
    Menu menu;
    menu.show();

    return a.exec();
}
