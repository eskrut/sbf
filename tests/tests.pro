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

CONFIG += c++11

INCLUDEPATH += ./../src

LIBS += -lsbf-dev \
        -L "$$OUT_PWD"/../build-libsbf-debug

SOURCES += \
    main.cpp \
    test_sbfNode.cpp \
    test_sbfAdditions.cpp \
    test_sbfElement.cpp \
    test_sbfMesh.cpp \
    test_sbfWorker.cpp \
    test_sbfParalleltask.cpp \
    test_stiffMatrixes.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    test_sbfNode.h \
    test_sbfAdditions.h \
    test_sbfElement.h \
    test_sbfMesh.h \
    test_sbfWorker.h \
    test_sbfParalleltask.h \
    test_stiffMatrixes.h
