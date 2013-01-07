#-------------------------------------------------
#
# Project created by QtCreator 2012-11-17T15:59:01
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = coding-practice
CONFIG   += console debug
CONFIG   -= app_bundle

CXXFLAGS += -std=c++0x

TEMPLATE = app

SOURCES += main.cpp \
    linkedlists.h \
    strings.cpp \
    dynamic_programming.cpp

HEADERS += \
    trees_heaps.h \
    strings.h \
    utils.h \
    dynamic_programming.h
