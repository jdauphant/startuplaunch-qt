#-------------------------------------------------
#
# Project created by QtCreator 2013-09-17T15:14:20
#
#-------------------------------------------------
CONFIG(debug, debug|release) {
     DEFAULT_SUBDIR = debug
}
else: {
     DEFAULT_SUBDIR = release
}
DESTDIR = $$PWD/../lib/$$DEFAULT_SUBDIR

QT       = core gui

TARGET = startuplaunch-qt
TEMPLATE = lib
CONFIG += staticlib

unix:!macx {
    SOURCES += startuplaunch_unix.cpp
}

macx {
    SOURCES += startuplaunch_macx.cpp
}


HEADERS += startuplaunch.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

SOURCES += \
    startuplaunch_macx.cpp
