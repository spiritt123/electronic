#include <QApplication>
#include "window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Window window(0, 1800, 800);
    window.show();    

    return a.exec();
}
