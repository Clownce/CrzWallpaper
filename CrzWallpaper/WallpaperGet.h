#ifndef WALLPAPERGET_H
#define WALLPAPERGET_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QFile>
#include <QDir>
#include <QIODevice>
#include <QSettings>
#include <QImage>
#include <QTimer>
#include <QDir>

class WallpaperGet : public QObject
{
	Q_OBJECT

public:
	void setWallpaper();
	void updateData();
	WallpaperGet(QObject *parent = 0);
	~WallpaperGet();

private:
	QNetworkAccessManager *managerXML;
	QNetworkAccessManager *managerIMG;
	QNetworkReply *m_Reply;
	QFile *m_File;
	QTimer *m_Timer;
	QString getMidStr(QString all, QString start, QString end);
private slots:
	void replayFinished(QNetworkReply *);
	void readyRead();
	void downloadFinished();
	void timeOut();
signals:
	void transNameSig(QString);
};

#endif // WALLPAPERGET_H
