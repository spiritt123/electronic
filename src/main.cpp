#include "window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Window window(480, 640);
    window.start();    

    return a.exec();
}
