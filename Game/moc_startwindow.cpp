/****************************************************************************
** Meta object code from reading C++ file 'startwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "startwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'startwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StartWindow_t {
    QByteArrayData data[17];
    char stringdata0[265];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StartWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StartWindow_t qt_meta_stringdata_StartWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "StartWindow"
QT_MOC_LITERAL(1, 12, 9), // "startGame"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "mapWidth"
QT_MOC_LITERAL(4, 32, 9), // "mapHeight"
QT_MOC_LITERAL(5, 42, 9), // "playerOne"
QT_MOC_LITERAL(6, 52, 9), // "playerTwo"
QT_MOC_LITERAL(7, 62, 14), // "playerOneColor"
QT_MOC_LITERAL(8, 77, 14), // "playerTwoColor"
QT_MOC_LITERAL(9, 92, 21), // "on_playButton_clicked"
QT_MOC_LITERAL(10, 114, 37), // "on_mapSizeComboBox_currentTex..."
QT_MOC_LITERAL(11, 152, 5), // "value"
QT_MOC_LITERAL(12, 158, 25), // "on_playerOneColor_clicked"
QT_MOC_LITERAL(13, 184, 25), // "on_playerTwoColor_clicked"
QT_MOC_LITERAL(14, 210, 24), // "on_playerOne_textChanged"
QT_MOC_LITERAL(15, 235, 4), // "arg1"
QT_MOC_LITERAL(16, 240, 24) // "on_playerTwo_textChanged"

    },
    "StartWindow\0startGame\0\0mapWidth\0"
    "mapHeight\0playerOne\0playerTwo\0"
    "playerOneColor\0playerTwoColor\0"
    "on_playButton_clicked\0"
    "on_mapSizeComboBox_currentTextChanged\0"
    "value\0on_playerOneColor_clicked\0"
    "on_playerTwoColor_clicked\0"
    "on_playerOne_textChanged\0arg1\0"
    "on_playerTwo_textChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StartWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    6,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   62,    2, 0x08 /* Private */,
      10,    1,   63,    2, 0x08 /* Private */,
      12,    0,   66,    2, 0x08 /* Private */,
      13,    0,   67,    2, 0x08 /* Private */,
      14,    1,   68,    2, 0x08 /* Private */,
      16,    1,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::QString, QMetaType::QString, QMetaType::QColor, QMetaType::QColor,    3,    4,    5,    6,    7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   15,

       0        // eod
};

void StartWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StartWindow *_t = static_cast<StartWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startGame((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QColor(*)>(_a[5])),(*reinterpret_cast< QColor(*)>(_a[6]))); break;
        case 1: _t->on_playButton_clicked(); break;
        case 2: _t->on_mapSizeComboBox_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_playerOneColor_clicked(); break;
        case 4: _t->on_playerTwoColor_clicked(); break;
        case 5: _t->on_playerOne_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_playerTwo_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (StartWindow::*_t)(unsigned int , unsigned int , QString , QString , QColor , QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StartWindow::startGame)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject StartWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_StartWindow.data,
      qt_meta_data_StartWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *StartWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StartWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StartWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int StartWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void StartWindow::startGame(unsigned int _t1, unsigned int _t2, QString _t3, QString _t4, QColor _t5, QColor _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
