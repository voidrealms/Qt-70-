#-------------------------------------------------
#
# Project created by QtCreator 2011-04-22T11:50:43
#
#-------------------------------------------------

QT       += core
QT       += network
QT       -= gui

TARGET = AsSvr2
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    myserver.cpp \
    myclient.cpp \
    mytask.cpp

HEADERS += \
    myserver.h \
    myclient.h \
    mytask.h
