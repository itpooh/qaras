#-------------------------------------------------
#
# Project created by QtCreator 2013-09-05T12:48:30
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = qaras
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app



SOURCES += main.cpp \
    qaras.cpp

include(qtservice-2.6-opensource/src/qtservice.pri)

HEADERS += \
    qaras.h
