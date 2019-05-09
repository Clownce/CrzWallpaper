#include <QApplication>
#include "Wallpaper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Wallpaper wallpaper;
    wallpaper.show();

    return a.exec();
}
