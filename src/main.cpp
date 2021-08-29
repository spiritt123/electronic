#include <QApplication>
#include "window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Window window(0, 800, 400);
    window.show();    

    return a.exec();
}
