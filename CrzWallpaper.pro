#-------------------------------------------------
#
# Project created by QtCreator 2019-05-09T15:35:37
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RC_ICONS = app.ico
VERSION = 1.5.0.0
QMAKE_TARGET_PRODUCT = CrzWallpaper
QMAKE_TARGET_COMPANY = Clownce
QMAKE_TARGET_COPYRIGHT = Copyright(C) 2019 Clownce

TARGET = CrzWallpaper
TEMPLATE = app


SOURCES += main.cpp \
    Wallpaper.cpp \
    WallpaperConfig.cpp \
    WallpaperGet.cpp

HEADERS  += \
    Wallpaper.h \
    WallpaperConfig.h \
    WallpaperGet.h

RESOURCES += \
    crzwallpaper.qrc
