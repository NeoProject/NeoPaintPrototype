#-------------------------------------------------
#
# Project created by QtCreator 2017-12-29T18:35:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NeoPaintPrototype
TEMPLATE = app
Release: DEFINES += QT_NO_DEBUG_OUTPUT

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
        main.cpp \
        nmainwindow.cpp \
    NGadget/nstatusbar.cpp \
    NGadget/ntoolbar.cpp \
    NGadget/nmenubar.cpp \
    NGadget/nabout.cpp \
    NGadget/ntablettest.cpp \
    NCanvas/ncanvasview.cpp \
    NCanvas/ntabwidget.cpp \
    NCanvas/ncanvas.cpp \
    NDockWidget/ndockwidget.cpp \
    NTool/ncolorcontainer.cpp \
    NTool/nlayercontainer.cpp \
    NGadget/nstatusmessage.cpp

HEADERS += \
        nmainwindow.h \
    NGadget/nstatusbar.h \
    NGadget/ntoolbar.h \
    NGadget/nmenubar.h \
    NGadget/nabout.h \
    NGadget/ntablettest.h \
    NCanvas/ncanvasview.h \
    NCanvas/ntabwidget.h \
    NCanvas/ncanvas.h \
    NDockWidget/ndockwidget.h \
    NTool/ncolorcontainer.h \
    NTool/nlayercontainer.h \
    NGadget/nstatusmessage.h

DISTFILES += \
    README.md
