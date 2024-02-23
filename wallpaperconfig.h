#pragma once
#include <Windows.h>
#include <string>

enum WallpaperStyle
{
	Tile,//平铺
	Center,//居中
	Stretch,//拉伸
	Fit, //适应
	Fill//填充
};
class WallpaperConfig
{
public:
	HRESULT SetDesktopWallpaper(PWSTR pszFile, WallpaperStyle style);
	WallpaperConfig();
	~WallpaperConfig();
private:
    PWSTR formatValue(std::string str);
};

