#include "WallpaperConfig.h"

WallpaperConfig::WallpaperConfig()
{
}
WallpaperConfig::~WallpaperConfig()
{
}
//https://blog.csdn.net/zy_dreamer/article/details/8877857?utm_source=tuicool
//   FUNCTION: SetDesktopWallpaper(PCWSTR, WallpaperStyle)
//
//   PURPOSE: Set the desktop wallpaper.
//
//   PARAMETERS: 
//   * pszFile - Path of the wallpaper
//   * style - Wallpaper style
//
HRESULT WallpaperConfig::SetDesktopWallpaper(PWSTR pszFile, WallpaperStyle style)
{
	HRESULT hr = S_OK;

	//���ñ�ֽ����չ����ʽ
	//��Control Panel\Desktop�е�������ֵ��������
	// TileWallpaper
	//  0: ͼƬ����ƽ�� 
	//  1: ��ƽ�� 
	// WallpaperStyle
	//  0:  0��ʾͼƬ���У�1��ʾƽ��
	//  2:  �������������Ļ
	//  6:  ������Ӧ��Ļ�����ָ߶ȱ�
	//  10: ͼƬ��������С�ü���Ӧ��Ļ�����ݺ��

	//�Կɶ���д�ķ�ʽ��HKCU\Control Panel\Desktopע�����
	HKEY hKey = NULL;
	hr = HRESULT_FROM_WIN32(RegOpenKeyEx(HKEY_CURRENT_USER,
		L"Control Panel\\Desktop", 0, KEY_READ | KEY_WRITE, &hKey));
	if (SUCCEEDED(hr))
	{
		PWSTR pszWallpaperStyle;
		PWSTR pszTileWallpaper;

		switch (style)
		{
		case Tile:
			pszWallpaperStyle = L"0";
			pszTileWallpaper = L"1";
			break;

		case Center:
			pszWallpaperStyle = L"0";
			pszTileWallpaper = L"0";
			break;

		case Stretch:
			pszWallpaperStyle = L"2";
			pszTileWallpaper = L"0";
			break;

		case Fit: // (Windows 7 and later)
			pszWallpaperStyle = L"6";
			pszTileWallpaper = L"0";
			break;

		case Fill: // (Windows 7 and later)
			pszWallpaperStyle = L"10";
			pszTileWallpaper = L"0";
			break;
		}
		// ���� WallpaperStyle �� TileWallpaper ��ע�����.
		DWORD cbData = lstrlen(pszWallpaperStyle) * sizeof(*pszWallpaperStyle);
		hr = HRESULT_FROM_WIN32(RegSetValueEx(hKey, L"WallpaperStyle", 0, REG_SZ,
			reinterpret_cast<const BYTE *>(pszWallpaperStyle), cbData));
		if (SUCCEEDED(hr))
		{
			cbData = lstrlen(pszTileWallpaper) * sizeof(*pszTileWallpaper);
			hr = HRESULT_FROM_WIN32(RegSetValueEx(hKey, L"TileWallpaper", 0, REG_SZ,
				reinterpret_cast<const BYTE *>(pszTileWallpaper), cbData));
		}

		RegCloseKey(hKey);
	}

	//ͨ������Win32 API����SystemParametersInfo ���������ֽ
	/************************************************
	֮ǰ�����Ѿ������˱�ֽ�����ͣ����Ǳ�ֽͼƬ��ʵ���ļ�·����û
	���á�SystemParametersInfo �������λ��user32.dll�У���֧��
	���Ǵ�ϵͳ�л��Ӳ����������Ϣ�������ĸ���������һ��ָ��������
	��������Ҫִ�еĲ���������������������ָ����Ҫ���õ����ݣ�����
	��һ���������趨�����һ������ָ���ı��Ƿ񱻱��档�����һ������
	����Ӧָ��SPI_SETDESKWALLPAPER��ָ��������Ҫ���ñ�ֽ����������
	�ļ�·������Vista֮ǰ������һ��.bmp���ļ���Vista�͸��߼���ϵͳ
	֧��.jpg��ʽ
	*************************************************/
	//SPI_SETDESKWALLPAPER����ʹ�ñ�ֽ�ı䱣�沢�����ɼ���
	if (SUCCEEDED(hr))
	{
		if (!SystemParametersInfo(SPI_SETDESKWALLPAPER, 0,
			static_cast<PVOID>(pszFile),
			SPIF_UPDATEINIFILE | SPIF_SENDWININICHANGE))
		{
			hr = HRESULT_FROM_WIN32(GetLastError());
		}
	}
	return hr;
}