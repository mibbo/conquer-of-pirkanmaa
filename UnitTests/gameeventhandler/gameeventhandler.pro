#-------------------------------------------------
#
# Project created by QtCreator 2019-12-01T17:33:33
#
#-------------------------------------------------

QT       += widgets

#QT_VERSION = 5

#equals(QT_VERSION, 5){
#    QT += widgets
#}

#equals(QT_VERSION, 4) {
#    QT += gui
#}

QT       += testlib

QT       += gui

TARGET = tst_gameeventhandlertest
CONFIG   += console
CONFIG   -= app_bundle

CONFIG += c++14

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
        tst_gameeventhandlertest.cpp \
#    ../../Game/cobblestone.cpp \
#    ../../Game/constructionworker.cpp \
#    ../../Game/game.cpp \
    ../../Game/gameeventhandler.cpp \
#    ../../Game/gamescene.cpp \
#    ../../Game/hoverbutton.cpp \
##    ../../Game/main.cpp \
#    ../../Game/mapitem.cpp \
#    ../../Game/mine.cpp \
#    ../../Game/mountain.cpp \
#    ../../Game/objectmanager.cpp \
    ../../Game/player.cpp \
#    ../../Game/quarry.cpp \
#    ../../Game/river.cpp \
#    ../../Game/sawmill.cpp \
#    ../../Game/startwindow.cpp \
#    ../../Game/warrior.cpp \
    ../../Course/CourseLib/core/playerbase.cpp \
    ../../Course/CourseLib/core/basicresources.cpp \
    ../../Course/CourseLib/core/coordinate.cpp \
    ../../Course/CourseLib/core/gameobject.cpp

HEADERS += \ ../../Game/gameeventhandler.hh

FORMS += \
    ../../Game/game.ui \
    ../../Game/startwindow.ui

INCLUDEPATH += \
        $$PWD/../../Course/CourseLib \
        $$PWD/../../Game

DEPENDPATH += \
        $$PWD/../../Course/CourseLib \
        $$PWD/../../Game
