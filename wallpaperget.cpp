#include "wallpaperget.h"
#include "wallpaperconfig.h"
#include <atlbase.h>
#include <atlconv.h>

WallpaperGet::WallpaperGet(QObject *parent)
	: QObject(parent)
{
	managerXML = new QNetworkAccessManager(this);
	managerIMG = new QNetworkAccessManager(this);
	m_Timer = new QTimer(this);
	m_savePathJpg = "";
	m_savePathBmp = "";
	connect(managerXML, SIGNAL(finished(QNetworkReply*)), this, SLOT(replayFinished(QNetworkReply*)));
	connect(m_Timer, SIGNAL(timeout()), this, SLOT(timeOut()));
}

WallpaperGet::~WallpaperGet()
{
}
void WallpaperGet::updateData()
{
    managerXML->get(QNetworkRequest(QUrl("https://cn.bing.com/HPImageArchive.aspx?format=xml&idx=0&n=1")));
}
void WallpaperGet::timeOut()
{
    managerXML->get(QNetworkRequest(QUrl("https://cn.bing.com/HPImageArchive.aspx?format=xml&idx=0&n=1")));
}
void WallpaperGet::setWallpaper()
{
    managerXML->get(QNetworkRequest(QUrl("https://cn.bing.com/HPImageArchive.aspx?format=xml&idx=0&n=1")));
	m_Timer->start(3600000);
}
QString WallpaperGet::getMidStr(QString all, QString start, QString end)
{
	QString ret;
	int indexS = all.indexOf(start) + start.size();
	int indexE = all.indexOf(end);
	int n = indexE - indexS;
	ret.append(all.mid(indexS, n));
	return ret;
}
void WallpaperGet::replayFinished(QNetworkReply *reply)
{
	QString all = QString(reply->readAll());//一个XML文件
    QString data = "https://cn.bing.com";//生成真正图片地址
	data.append(getMidStr(all, "<url>", "</url>"));
	data.replace("1366x768", "1920x1080");
	QString copyright = "";
	copyright = getMidStr(all, "<copyright>", "</copyright>");
	emit transNameSig(copyright);
	QDir dir;
	dir.setCurrent(QDir::homePath());
	dir.cd("Documents");
	dir.refresh();
	m_savePathJpg = dir.absolutePath();
	m_savePathBmp = m_savePathJpg;
	dir.mkdir("CrzWallpaper");
	m_savePathJpg += "/CrzWallpaper/wallpaper.jpg";
	m_savePathBmp += "/CrzWallpaper/wallpaper.bmp";
	m_File = new QFile(m_savePathJpg);
	if (!m_File->open(QIODevice::WriteOnly)) return;
	m_Reply = managerIMG->get(QNetworkRequest(QUrl(data)));
	connect(m_Reply, SIGNAL(finished()), this, SLOT(downloadFinished()));
	connect(m_Reply, SIGNAL(readyRead()), this, SLOT(readyRead()));
}
void WallpaperGet::readyRead()
{
	if (m_File != NULL) m_File->write(m_Reply->readAll());
}
void WallpaperGet::downloadFinished()
{
	m_File->flush();
	m_File->close();
	m_Reply->deleteLater();
	m_Reply = 0;
	delete m_File;
	m_File = 0;
	QImage img;
	img.load(m_savePathJpg);
	img.save(m_savePathBmp);
	//QFileInfo fileInfo("./Wallpaper/img.bmp");
	std::string sStr= m_savePathBmp.toStdString();
	USES_CONVERSION;
	PWSTR pStr = A2W(sStr.c_str());
	WallpaperConfig wallConfig;
	wallConfig.SetDesktopWallpaper(pStr, WallpaperStyle::Fill);
}
