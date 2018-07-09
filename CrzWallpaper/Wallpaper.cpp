#include "Wallpaper.h"

Wallpaper::Wallpaper(QObject *parent)
	: QSystemTrayIcon(parent)
{
	isStartup = true;
	REG_RUN = "HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run";
	this->setIcon(QIcon(":/CrzWallpaper/Resources/cat.png"));
	this->setToolTip("CrzWallpaper");
	wallpaperGet = new WallpaperGet;
	menu = new QMenu;
	actQuit = new QAction(menu);
	actQuit->setText("�˳�");
	actQuit->setToolTip("�˳�");
	actQuit->setIcon(QIcon(":/CrzWallpaper/Resources/quit.png"));
	actStartup = new QAction(menu);
	actStartup->setText("��������");
	actStartup->setToolTip("�����ÿ�������");
	actStartup->setIcon(QIcon(":/CrzWallpaper/Resources/startupon.png"));
	actName = new QAction(menu);
	actName->setEnabled(false);
	menu->addAction(actName);
	menu->addSeparator();
	menu->addAction(actStartup);
	menu->addAction(actQuit);
	this->setContextMenu(menu);
	wallpaperGet->setWallpaper();
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
		actStartup->setIcon(QIcon(":/CrzWallpaper/Resources/startupoff.png"));
		actStartup->setToolTip("��ȡ����������");
		isStartup = false;
	}
	else
	{
		QString appPath = QApplication::applicationFilePath();
		regSettings.setValue(appName, appPath.replace("/", "\\"));
		actStartup->setIcon(QIcon(":/CrzWallpaper/Resources/startupon.png"));
		actStartup->setToolTip("�����ÿ�������");
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