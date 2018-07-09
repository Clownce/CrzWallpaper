#ifndef WALLPAPER_H
#define WALLPAPER_H

#include <QSystemTrayIcon>
#include <QIcon>
#include <QAction>
#include <QMenu>
#include <QApplication>
#include <QSettings>
#include "WallpaperGet.h"

#pragma execution_character_set("UTF-8")
class Wallpaper : public QSystemTrayIcon
{
	Q_OBJECT

public:
	Wallpaper(QObject *parent = 0);
	~Wallpaper();

private:
	bool isStartup;//是否开机启动
	QString REG_RUN;//注册表路径
	WallpaperGet *wallpaperGet;
	QMenu *menu;
	QAction *actQuit;
	QAction *actStartup;
	QAction *actName;
private slots:
	void quitSlot();
	void startupSlot();
	void showNameSlot(QString name);
};

#endif // WALLPAPER_H
