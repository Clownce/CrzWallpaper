/****************************************************************************
** Meta object code from reading C++ file 'WallpaperGet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../WallpaperGet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WallpaperGet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WallpaperGet_t {
    QByteArrayData data[8];
    char stringdata[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WallpaperGet_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WallpaperGet_t qt_meta_stringdata_WallpaperGet = {
    {
QT_MOC_LITERAL(0, 0, 12), // "WallpaperGet"
QT_MOC_LITERAL(1, 13, 12), // "transNameSig"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14), // "replayFinished"
QT_MOC_LITERAL(4, 42, 14), // "QNetworkReply*"
QT_MOC_LITERAL(5, 57, 9), // "readyRead"
QT_MOC_LITERAL(6, 67, 16), // "downloadFinished"
QT_MOC_LITERAL(7, 84, 7) // "timeOut"

    },
    "WallpaperGet\0transNameSig\0\0replayFinished\0"
    "QNetworkReply*\0readyRead\0downloadFinished\0"
    "timeOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WallpaperGet[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   42,    2, 0x08 /* Private */,
       5,    0,   45,    2, 0x08 /* Private */,
       6,    0,   46,    2, 0x08 /* Private */,
       7,    0,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WallpaperGet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WallpaperGet *_t = static_cast<WallpaperGet *>(_o);
        switch (_id) {
        case 0: _t->transNameSig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->replayFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->readyRead(); break;
        case 3: _t->downloadFinished(); break;
        case 4: _t->timeOut(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WallpaperGet::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WallpaperGet::transNameSig)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject WallpaperGet::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WallpaperGet.data,
      qt_meta_data_WallpaperGet,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WallpaperGet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WallpaperGet::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WallpaperGet.stringdata))
        return static_cast<void*>(const_cast< WallpaperGet*>(this));
    return QObject::qt_metacast(_clname);
}

int WallpaperGet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void WallpaperGet::transNameSig(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
