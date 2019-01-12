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
    QByteArrayData data[14];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pdf_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pdf_t qt_meta_stringdata_pdf = {
    {
QT_MOC_LITERAL(0, 0, 3), // "pdf"
QT_MOC_LITERAL(1, 4, 17), // "startedConverting"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 15), // "progressUpdated"
QT_MOC_LITERAL(4, 39, 4), // "perc"
QT_MOC_LITERAL(5, 44, 14), // "newlyConverted"
QT_MOC_LITERAL(6, 59, 11), // "std::string"
QT_MOC_LITERAL(7, 71, 16), // "convertedImgName"
QT_MOC_LITERAL(8, 88, 18), // "finishedConverting"
QT_MOC_LITERAL(9, 107, 8), // "timeTook"
QT_MOC_LITERAL(10, 116, 12), // "sendImgPaths"
QT_MOC_LITERAL(11, 129, 24), // "std::vector<std::string>"
QT_MOC_LITERAL(12, 154, 5), // "paths"
QT_MOC_LITERAL(13, 160, 13) // "ConvertToImgs"

    },
    "pdf\0startedConverting\0\0progressUpdated\0"
    "perc\0newlyConverted\0std::string\0"
    "convertedImgName\0finishedConverting\0"
    "timeTook\0sendImgPaths\0std::vector<std::string>\0"
    "paths\0ConvertToImgs"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pdf[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,
       5,    1,   48,    2, 0x06 /* Public */,
       8,    1,   51,    2, 0x06 /* Public */,
      10,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::LongLong,    9,
    QMetaType::Void, 0x80000000 | 11,   12,

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
        case 0: _t->startedConverting(); break;
        case 1: _t->progressUpdated((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->newlyConverted((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 3: _t->finishedConverting((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 4: _t->sendImgPaths((*reinterpret_cast< std::vector<std::string>(*)>(_a[1]))); break;
        case 5: _t->ConvertToImgs(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (pdf::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pdf::startedConverting)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (pdf::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pdf::progressUpdated)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (pdf::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pdf::newlyConverted)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (pdf::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pdf::finishedConverting)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (pdf::*)(std::vector<std::string> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pdf::sendImgPaths)) {
                *result = 4;
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
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void pdf::startedConverting()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void pdf::progressUpdated(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void pdf::newlyConverted(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void pdf::finishedConverting(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void pdf::sendImgPaths(std::vector<std::string> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
