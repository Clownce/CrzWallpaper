#include "wallpaper.h"

Wallpaper::Wallpaper(QObject *parent)
    : QSystemTrayIcon(parent)
{
    isStartup = true;
    REG_RUN = "HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run";
    this->setIcon(QIcon(":/crzwallpaper/resources/cat.png"));
    this->setToolTip("CrzWallpaper");
    wallpaperGet = new WallpaperGet;
    menu = new QMenu();
    actQuit = new QAction(menu);
    actQuit->setText("退出");
    actQuit->setToolTip("退出");
    actQuit->setIcon(QIcon(":/crzwallpaper/resources/quit.png"));
    actStartup = new QAction(menu);
    actStartup->setText("开机启动");
    actStartup->setToolTip("已设置开机启动");
    actStartup->setIcon(QIcon(":/crzwallpaper/resources/startupon.png"));
    actName = new QAction(menu);
    actName->setEnabled(false);
    actUpdate = new QAction(menu);
    actUpdate->setText("刷新");
    actUpdate->setIcon(QIcon(":/crzwallpaper/resources/update.png"));
    menu->addAction(actName);
    menu->addSeparator();
    menu->addAction(actUpdate);
    menu->addAction(actStartup);
    menu->addAction(actQuit);
    this->setContextMenu(menu);
    wallpaperGet->setWallpaper();
    connect(actUpdate, SIGNAL(triggered()), this, SLOT(updateSlot()));
    connect(actStartup, SIGNAL(triggered()), this, SLOT(startupSlot()));
    connect(actQuit, SIGNAL(triggered()), this, SLOT(quitSlot()));
    connect(wallpaperGet, SIGNAL(transNameSig(QString)), this, SLOT(showNameSlot(QString)));

    QString appName = QApplication::applicationName();
    QSettings regSettings(REG_RUN, QSettings::NativeFormat);
    QString appPath = QApplication::applicationFilePath();
    regSettings.setValue(appName, appPath.replace("/", "\\"));
}
Wallpaper::~Wallpaper()
{
}
void Wallpaper::startupSlot()
{
    QString appName = QApplication::applicationName();
    QSettings regSettings(REG_RUN, QSettings::NativeFormat);
    if (isStartup)
    {
        regSettings.remove(appName);
        actStartup->setIcon(QIcon(":/crzwallpaper/resources/startupoff.png"));
        actStartup->setToolTip("已取消开机启动");
        isStartup = false;
    }
    else
    {
        QString appPath = QApplication::applicationFilePath();
        regSettings.setValue(appName, appPath.replace("/", "\\"));
        actStartup->setIcon(QIcon(":/crzwallpaper/resources/startupon.png"));
        actStartup->setToolTip("已设置开机启动");
        isStartup = true;
    }
}
void Wallpaper::quitSlot()
{
    QApplication::quit();
}
void Wallpaper::showNameSlot(QString name)
{
    actName->setText(name);
}
void Wallpaper::updateSlot()
{
    wallpaperGet->updateData();
}
