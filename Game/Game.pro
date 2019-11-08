TEMPLATE = app
TARGET = TheGame

QT += core gui widgets

CONFIG += c++14

SOURCES += \
    game.cpp \
    gamescene.cpp \
    main.cpp \
    mapitem.cpp \
    mapwindow.cc \
    objectmanager.cpp \
<<<<<<< HEAD
    myworldgenerator.cpp \
    gameeventhandler.cpp \
    mymapwindow.cpp \
    mymapitem.cpp \
    mygamescene.cpp \
    startwindow.cpp
=======
    gameeventhandler.cpp
>>>>>>> dev

HEADERS += \
    game.h \
    gamescene.h \
    mapitem.h \
    mapwindow.hh \
    gameeventhandler.hh \
<<<<<<< HEAD
    objectmanager.hh \
    myworldgenerator.hh \
    mymapwindow.hh \
    mymapitem.hh \
    mygamescene.hh \
    startwindow.hh
=======
    objectmanager.hh
>>>>>>> dev

win32:CONFIG(release, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/release/ -lCourseLib
else:win32:CONFIG(debug, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/debug/ -lCourseLib
else:unix: LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/ -lCourseLib

INCLUDEPATH += \
    $$PWD/../Course/CourseLib

DEPENDPATH += \
    $$PWD/../Course/CourseLib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/libCourseLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/libCourseLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/CourseLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/CourseLib.lib
else:unix: PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/libCourseLib.a

FORMS += \
<<<<<<< HEAD
    mapwindow.ui \
    startwindow.ui
=======
    game.ui \
    mapwindow.ui
>>>>>>> dev
