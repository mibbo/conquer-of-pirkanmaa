TEMPLATE = app

QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

HEADERS += \
    $$PWD/../../CourseLib/core/coordinate.h

SOURCES +=  \
    tst_default_coordinate.cpp \
    $$PWD/../../CourseLib/core/coordinate.cpp

INCLUDEPATH += \
    $$PWD/../../CourseLib/
