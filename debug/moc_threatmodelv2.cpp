/****************************************************************************
** Meta object code from reading C++ file 'threatmodelv2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../threatmodelv2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threatmodelv2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_threatmodelv2_t {
    QByteArrayData data[10];
    char stringdata[181];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_threatmodelv2_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_threatmodelv2_t qt_meta_stringdata_threatmodelv2 = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 21),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 23),
QT_MOC_LITERAL(4, 61, 23),
QT_MOC_LITERAL(5, 85, 5),
QT_MOC_LITERAL(6, 91, 22),
QT_MOC_LITERAL(7, 114, 19),
QT_MOC_LITERAL(8, 134, 21),
QT_MOC_LITERAL(9, 156, 23)
    },
    "threatmodelv2\0on_pushButton_clicked\0"
    "\0on_pushButton_2_clicked\0"
    "on_listWidget_activated\0index\0"
    "on_checkBox_29_clicked\0on_action_triggered\0"
    "on_action_2_triggered\0on_pushButton_3_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_threatmodelv2[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08,
       3,    0,   50,    2, 0x08,
       4,    1,   51,    2, 0x08,
       6,    0,   54,    2, 0x08,
       7,    0,   55,    2, 0x08,
       8,    0,   56,    2, 0x08,
       9,    0,   57,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void threatmodelv2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        threatmodelv2 *_t = static_cast<threatmodelv2 *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->on_listWidget_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_checkBox_29_clicked(); break;
        case 4: _t->on_action_triggered(); break;
        case 5: _t->on_action_2_triggered(); break;
        case 6: _t->on_pushButton_3_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject threatmodelv2::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_threatmodelv2.data,
      qt_meta_data_threatmodelv2,  qt_static_metacall, 0, 0}
};


const QMetaObject *threatmodelv2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *threatmodelv2::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_threatmodelv2.stringdata))
        return static_cast<void*>(const_cast< threatmodelv2*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int threatmodelv2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
