/****************************************************************************
** Meta object code from reading C++ file 'game.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "game.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Game_t {
    QByteArrayData data[26];
    char stringdata0[344];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Game_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Game_t qt_meta_stringdata_Game = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Game"
QT_MOC_LITERAL(1, 5, 16), // "playInTurnSignal"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 32), // "std::shared_ptr<Student::Player>"
QT_MOC_LITERAL(4, 56, 13), // "playerInTurn_"
QT_MOC_LITERAL(5, 70, 14), // "buildingSignal"
QT_MOC_LITERAL(6, 85, 11), // "std::string"
QT_MOC_LITERAL(7, 97, 8), // "building"
QT_MOC_LITERAL(8, 106, 13), // "startGameSlot"
QT_MOC_LITERAL(9, 120, 8), // "mapWidth"
QT_MOC_LITERAL(10, 129, 9), // "mapHeight"
QT_MOC_LITERAL(11, 139, 9), // "playerOne"
QT_MOC_LITERAL(12, 149, 9), // "playerTwo"
QT_MOC_LITERAL(13, 159, 14), // "playerOneColor"
QT_MOC_LITERAL(14, 174, 14), // "playerTwoColor"
QT_MOC_LITERAL(15, 189, 14), // "updateViewSlot"
QT_MOC_LITERAL(16, 204, 14), // "sendButtonText"
QT_MOC_LITERAL(17, 219, 21), // "updateInformationSlot"
QT_MOC_LITERAL(18, 241, 9), // "movesLeft"
QT_MOC_LITERAL(19, 251, 12), // "gameOverSlot"
QT_MOC_LITERAL(20, 264, 6), // "winner"
QT_MOC_LITERAL(21, 271, 9), // "turnCount"
QT_MOC_LITERAL(22, 281, 14), // "logMessageSlot"
QT_MOC_LITERAL(23, 296, 7), // "message"
QT_MOC_LITERAL(24, 304, 17), // "enableButtonsSlot"
QT_MOC_LITERAL(25, 322, 21) // "on_turnButton_clicked"

    },
    "Game\0playInTurnSignal\0\0"
    "std::shared_ptr<Student::Player>\0"
    "playerInTurn_\0buildingSignal\0std::string\0"
    "building\0startGameSlot\0mapWidth\0"
    "mapHeight\0playerOne\0playerTwo\0"
    "playerOneColor\0playerTwoColor\0"
    "updateViewSlot\0sendButtonText\0"
    "updateInformationSlot\0movesLeft\0"
    "gameOverSlot\0winner\0turnCount\0"
    "logMessageSlot\0message\0enableButtonsSlot\0"
    "on_turnButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Game[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       5,    1,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    6,   70,    2, 0x0a /* Public */,
      15,    0,   83,    2, 0x0a /* Public */,
      16,    0,   84,    2, 0x0a /* Public */,
      17,    1,   85,    2, 0x0a /* Public */,
      19,    2,   88,    2, 0x0a /* Public */,
      22,    1,   93,    2, 0x0a /* Public */,
      24,    0,   96,    2, 0x0a /* Public */,
      25,    0,   97,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::QString, QMetaType::QString, QMetaType::QColor, QMetaType::QColor,    9,   10,   11,   12,   13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,   20,   21,
    QMetaType::Void, 0x80000000 | 6,   23,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Game::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Game *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->playInTurnSignal((*reinterpret_cast< std::shared_ptr<Student::Player>(*)>(_a[1]))); break;
        case 1: _t->buildingSignal((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 2: _t->startGameSlot((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QColor(*)>(_a[5])),(*reinterpret_cast< QColor(*)>(_a[6]))); break;
        case 3: _t->updateViewSlot(); break;
        case 4: _t->sendButtonText(); break;
        case 5: _t->updateInformationSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->gameOverSlot((*reinterpret_cast< std::shared_ptr<Student::Player>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->logMessageSlot((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 8: _t->enableButtonsSlot(); break;
        case 9: _t->on_turnButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Game::*)(std::shared_ptr<Student::Player> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Game::playInTurnSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Game::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Game::buildingSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Game::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Game.data,
    qt_meta_data_Game,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Game::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Game::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Game.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Game::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Game::playInTurnSignal(std::shared_ptr<Student::Player> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Game::buildingSignal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
