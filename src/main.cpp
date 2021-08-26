#include <QApplication>
#include "window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Window window;
    //480, 640);
    window.show();    

    return a.exec();
}
