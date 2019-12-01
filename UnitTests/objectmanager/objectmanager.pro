#-------------------------------------------------
#
# Project created by QtCreator 2019-12-01T19:38:59
#
#-------------------------------------------------

QT       += testlib

QT       += gui

TARGET = tst_objectmanagertest
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


SOURCES += \
        tst_objectmanagertest.cpp \
        ../../Game/gameeventhandler.cpp \
        ../../Game/objectmanager.cpp \
        ../../Game/mountain.cpp \
        ../../Game/cobblestone.cpp \
        ../../Course/CourseLib/tiles/forest.cpp \
        ../../Course/CourseLib/core/coordinate.cpp \
        ../../Course/CourseLib/core/gameobject.cpp \
        ../../Course/CourseLib/tiles/tilebase.cpp \
        ../../Game/player.cpp \
        ../../Course/CourseLib/core/playerbase.cpp \
        ../../Course/CourseLib/core/basicresources.cpp \
        ../../Course/CourseLib/buildings/buildingbase.cpp \
        ../../Course/CourseLib/core/placeablegameobject.cpp

INCLUDEPATH += \
        $$PWD/../../Course/CourseLib \
        $$PWD/../../Game

DEPENDPATH += \
        $$PWD/../../Course/CourseLib \
        $$PWD/../../Game
