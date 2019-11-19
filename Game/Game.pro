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
    gameeventhandler.cpp \
    player.cpp \
    startwindow.cpp

HEADERS += \
    game.h \
    gamescene.h \
    mapitem.h \
    mapwindow.hh \
    gameeventhandler.hh \
    objectmanager.hh \
    player.h \
    startwindow.h

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

#fetch git short commit hash here
win32:DEFINES += GIT_BIN='C:\\Git\\bin\\git'
# or 'C:\\Progra~1\\Git\\bin\\git' - ymmv with putting spaces in here
win32:DEFINES += GIT_REVISION='\\"$$system($${GIT_BIN} rev-parse --short HEAD)\\"'
unix:DEFINES += GIT_REVISION='\\"$$system(git rev-parse --short HEAD)\\"'

FORMS += \
    game.ui \
    mapwindow.ui \
    startwindow.ui

RESOURCES += \
    resources.qrc
