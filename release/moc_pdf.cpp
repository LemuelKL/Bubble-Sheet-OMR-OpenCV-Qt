/****************************************************************************
** Meta object code from reading C++ file 'pdf.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pdf.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pdf.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pdf_t {
    QByteArrayData data[15];
    char stringdata0[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pdf_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pdf_t qt_meta_stringdata_pdf = {
    {
QT_MOC_LITERAL(0, 0, 3), // "pdf"
QT_MOC_LITERAL(1, 4, 12), // "badImgFormat"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 17), // "startedConverting"
QT_MOC_LITERAL(4, 36, 15), // "progressUpdated"
QT_MOC_LITERAL(5, 52, 4), // "perc"
QT_MOC_LITERAL(6, 57, 14), // "newlyConverted"
QT_MOC_LITERAL(7, 72, 11), // "std::string"
QT_MOC_LITERAL(8, 84, 16), // "convertedImgName"
QT_MOC_LITERAL(9, 101, 18), // "finishedConverting"
QT_MOC_LITERAL(10, 120, 8), // "timeTook"
QT_MOC_LITERAL(11, 129, 12), // "sendImgPaths"
QT_MOC_LITERAL(12, 142, 24), // "std::vector<std::string>"
QT_MOC_LITERAL(13, 167, 5), // "paths"
QT_MOC_LITERAL(14, 173, 13) // "ConvertToImgs"

    },
    "pdf\0badImgFormat\0\0startedConverting\0"
    "progressUpdated\0perc\0newlyConverted\0"
    "std::string\0convertedImgName\0"
    "finishedConverting\0timeTook\0sendImgPaths\0"
    "std::vector<std::string>\0paths\0"
    "ConvertToImgs"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pdf[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    1,   51,    2, 0x06 /* Public */,
       6,    1,   54,    2, 0x06 /* Public */,
       9,    1,   57,    2, 0x06 /* Public */,
      11,    1,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::LongLong,   10,
    QMetaType::Void, 0x80000000 | 12,   13,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void pdf::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pdf *_t = static_cast<pdf *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->badImgFormat(); break;
        case 1: _t->startedConverting(); break;
        case 2: _t->progressUpdated((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->newlyConverted((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 4: _t->finishedConverting((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 5: _t->sendImgPaths((*reinterpret_cast< std::vector<std::string>(*)>(_a[1]))); break;
        case 6: _t->ConvertToImgs(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (pdf::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pdf::badImgFormat)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (pdf::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pdf::startedConverting)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (pdf::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pdf::progressUpdated)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (pdf::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pdf::newlyConverted)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (pdf::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pdf::finishedConverting)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (pdf::*)(std::vector<std::string> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pdf::sendImgPaths)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject pdf::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_pdf.data,
      qt_meta_data_pdf,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *pdf::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pdf::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_pdf.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int pdf::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void pdf::badImgFormat()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void pdf::startedConverting()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void pdf::progressUpdated(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void pdf::newlyConverted(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void pdf::finishedConverting(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void pdf::sendImgPaths(std::vector<std::string> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
