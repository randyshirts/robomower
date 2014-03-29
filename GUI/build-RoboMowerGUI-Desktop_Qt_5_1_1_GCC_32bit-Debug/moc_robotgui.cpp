/****************************************************************************
** Meta object code from reading C++ file 'robotgui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../RoboMowerGUI/robotgui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'robotgui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RobotGui_t {
    QByteArrayData data[22];
    char stringdata[267];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RobotGui_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RobotGui_t qt_meta_stringdata_RobotGui = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 10),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 4),
QT_MOC_LITERAL(4, 26, 17),
QT_MOC_LITERAL(5, 44, 19),
QT_MOC_LITERAL(6, 64, 18),
QT_MOC_LITERAL(7, 83, 20),
QT_MOC_LITERAL(8, 104, 8),
QT_MOC_LITERAL(9, 113, 6),
QT_MOC_LITERAL(10, 120, 14),
QT_MOC_LITERAL(11, 135, 8),
QT_MOC_LITERAL(12, 144, 19),
QT_MOC_LITERAL(13, 164, 3),
QT_MOC_LITERAL(14, 168, 10),
QT_MOC_LITERAL(15, 179, 9),
QT_MOC_LITERAL(16, 189, 10),
QT_MOC_LITERAL(17, 200, 12),
QT_MOC_LITERAL(18, 213, 13),
QT_MOC_LITERAL(19, 227, 12),
QT_MOC_LITERAL(20, 240, 12),
QT_MOC_LITERAL(21, 253, 12)
    },
    "RobotGui\0getCommand\0\0data\0Up_Button_Pressed\0"
    "Down_Button_Pressed\0Up_Button_Released\0"
    "Down_Button_Released\0setSpeed\0newVal\0"
    "setBladeToggle\0bladeCmd\0speedSliderSettings\0"
    "val\0lightHBled\0darkHBled\0driveCmdUp\0"
    "driveCmdDown\0driveCmdRight\0driveCmdLeft\0"
    "driveStopCmd\0sendDriveCmd\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RobotGui[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x05,
       4,    0,  102,    2, 0x05,
       5,    0,  103,    2, 0x05,
       6,    0,  104,    2, 0x05,
       7,    0,  105,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       8,    1,  106,    2, 0x0a,
      10,    0,  109,    2, 0x0a,
      11,    0,  110,    2, 0x0a,
      12,    1,  111,    2, 0x0a,
      14,    0,  114,    2, 0x0a,
      15,    0,  115,    2, 0x0a,
      16,    0,  116,    2, 0x0a,
      17,    0,  117,    2, 0x0a,
      18,    0,  118,    2, 0x0a,
      19,    0,  119,    2, 0x0a,
      20,    0,  120,    2, 0x0a,
      21,    0,  121,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RobotGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RobotGui *_t = static_cast<RobotGui *>(_o);
        switch (_id) {
        case 0: _t->getCommand((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 1: _t->Up_Button_Pressed(); break;
        case 2: _t->Down_Button_Pressed(); break;
        case 3: _t->Up_Button_Released(); break;
        case 4: _t->Down_Button_Released(); break;
        case 5: _t->setSpeed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setBladeToggle(); break;
        case 7: _t->bladeCmd(); break;
        case 8: _t->speedSliderSettings((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->lightHBled(); break;
        case 10: _t->darkHBled(); break;
        case 11: _t->driveCmdUp(); break;
        case 12: _t->driveCmdDown(); break;
        case 13: _t->driveCmdRight(); break;
        case 14: _t->driveCmdLeft(); break;
        case 15: _t->driveStopCmd(); break;
        case 16: _t->sendDriveCmd(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RobotGui::*_t)(const QByteArray & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RobotGui::getCommand)) {
                *result = 0;
            }
        }
        {
            typedef void (RobotGui::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RobotGui::Up_Button_Pressed)) {
                *result = 1;
            }
        }
        {
            typedef void (RobotGui::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RobotGui::Down_Button_Pressed)) {
                *result = 2;
            }
        }
        {
            typedef void (RobotGui::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RobotGui::Up_Button_Released)) {
                *result = 3;
            }
        }
        {
            typedef void (RobotGui::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RobotGui::Down_Button_Released)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject RobotGui::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RobotGui.data,
      qt_meta_data_RobotGui,  qt_static_metacall, 0, 0}
};


const QMetaObject *RobotGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RobotGui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RobotGui.stringdata))
        return static_cast<void*>(const_cast< RobotGui*>(this));
    return QWidget::qt_metacast(_clname);
}

int RobotGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void RobotGui::getCommand(const QByteArray & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RobotGui::Up_Button_Pressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void RobotGui::Down_Button_Pressed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void RobotGui::Up_Button_Released()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void RobotGui::Down_Button_Released()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
