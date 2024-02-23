#include <QApplication>
#include "wallpaper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Wallpaper wallpaper;
    wallpaper.show();

    return a.exec();
}
