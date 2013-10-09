#-------------------------------------------------
#
# Project created by QtCreator 2013-10-08T11:55:07
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = libsbf_tests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += ./../src

LIBS += -lsbf-dev \
        -L "$$OUT_PWD"/../build-libsbf-debug

SOURCES += \
    main.cpp \
    test_sbfNode.cpp \
    test_sbfAdditions.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    test_sbfNode.h \
    test_sbfAdditions.h
