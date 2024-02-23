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
QMAKE_TARGET_COPYRIGHT = Copyright(C) 2024 Clownce

TARGET = CrzWallpaper
TEMPLATE = app


SOURCES += main.cpp \
    wallpaper.cpp \
    wallpaperconfig.cpp \
    wallpaperget.cpp

HEADERS  += \
    wallpaper.h \
    wallpaperconfig.h \
    wallpaperget.h

RESOURCES += \
    crzwallpaper.qrc
