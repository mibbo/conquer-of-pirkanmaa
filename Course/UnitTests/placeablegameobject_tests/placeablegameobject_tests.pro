#-------------------------------------------------
#
# Project created by QtCreator 2019-08-28T17:16:53
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_default_test
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    $$PWD/../../CourseLib/

HEADERS += \
    $$PWD/../../CourseLib/core/gameobject.h \
    $$PWD/../../CourseLib/core/coordinate.h \
    $$PWD/../../CourseLib/core/playerbase.h \
    $$PWD/../../CourseLib/tiles/tilebase.h \
    $$PWD/../../CourseLib/workers/workerbase.h \
    $$PWD/../../CourseLib/core/placeablegameobject.h


SOURCES += \
    $$PWD/../../CourseLib/core/gameobject.cpp \
    $$PWD/../../CourseLib/core/coordinate.cpp \
    $$PWD/../../CourseLib/core/playerbase.cpp \
    $$PWD/../../CourseLib/core/basicresources.cpp \
    $$PWD/../../CourseLib/tiles/tilebase.cpp \
    $$PWD/../../CourseLib/workers/workerbase.cpp \
    $$PWD/../../CourseLib/core/placeablegameobject.cpp \
    tst_default_test.cpp
