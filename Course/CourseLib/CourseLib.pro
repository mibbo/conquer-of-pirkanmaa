TEMPLATE = lib

CONFIG += c++14 staticlib

QT += core gui widgets

HEADERS += \
    buildings/buildingbase.h \
    buildings/farm.h \
    buildings/headquarters.h \
    buildings/outpost.h \
    exceptions/baseexception.h \
    exceptions/keyerror.h \
    exceptions/ownerconflict.h \
    exceptions/invalidpointer.h \
    exceptions/illegalaction.h \
    exceptions/notenoughspace.h \
    graphics/simplemapitem.h \
    graphics/simplegamescene.h \
    interfaces/iobjectmanager.h \
    interfaces/igameeventhandler.h \
    tiles/grassland.h \
    tiles/forest.h \
    tiles/tilebase.h \
    workers/basicworker.h \
    workers/workerbase.h \
    core/basicresources.h \
    core/placeablegameobject.h \
    core/worldgenerator.h \
    core/coordinate.h \
    core/playerbase.h \
    core/gameobject.h \
    core/resourcemaps.h


SOURCES += \
    buildings/buildingbase.cpp \
    buildings/headquarters.cpp \
    buildings/outpost.cpp \
    buildings/farm.cpp \
    tiles/grassland.cpp \
    graphics/simplemapitem.cpp \
    graphics/simplegamescene.cpp \
    tiles/forest.cpp \
    tiles/tilebase.cpp \
    workers/basicworker.cpp \
    workers/workerbase.cpp \
    core/placeablegameobject.cpp \
    core/worldgenerator.cpp \
    core/coordinate.cpp \
    core/playerbase.cpp \
    core/gameobject.cpp \
    core/basicresources.cpp
