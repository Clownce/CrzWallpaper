#pragma once
#include <Windows.h>

enum WallpaperStyle
{
	Tile,//ƽ��
	Center,//����
	Stretch,//����
	Fit, //��Ӧ
	Fill//���
};
class WallpaperConfig
{
public:
	HRESULT SetDesktopWallpaper(PWSTR pszFile, WallpaperStyle style);
	WallpaperConfig();
	~WallpaperConfig();
};

