#-------------------------------------------------
#
# Project created by QtCreator 2013-10-04T15:41:30
#
#-------------------------------------------------

QT       -= core gui

TARGET = sbf
CONFIG(debug, debug|release){
    TARGET = $$join(TARGET,,,-dev)
}
TEMPLATE = lib

DEFINES += LIBSBF_LIBRARY

CONFIG += c++11
QMAKE_CXXFLAGS += -Wall -pedantic

VER_MAJ = 0
VER_MIN = 3
VER_PAT = 0

SOURCES += \
    src/sbfNode.cpp \
    src/sbfElement.cpp \
    src/sbfMesh.cpp \
    src/sbfMeshBuilders.cpp \
    src/sbfGroupFilter.cpp \
    src/sbfGroup.cpp \
    src/sbfElementGroup.cpp \
    src/sbfNodeGroup.cpp \
    src/sbfSElement.cpp \
    src/sbfSELevel.cpp \
    src/sbfSELevelList.cpp \
    src/sbfPropertyTable.cpp \
    src/sbfMaterialProperties.cpp \
    src/sbfPropertiesSet.cpp \
    src/sbfStiffBlock3x3.cpp \
    src/sbfStiffMatrixBlock3x3.cpp \
    src/sbfElemStiffMatrixHexa8.cpp \
    src/sbfWorker.cpp \
    src/sbfParallelTask.cpp \
    src/sbfReporter.cpp \
    src/sbfMatrixIterator.cpp \
    src/sbfStiffMatrixBlock3x3Iterator.cpp

HEADERS += \
    src/sbf.h \
    src/sbfNode.h \
    src/sbfElement.h \
    src/sbfMesh.h \
    src/sbfGroupFilter.h \
    src/sbfAdditions.h \
    src/sbfGroup.h \
    src/sbfElementGroup.h \
    src/sbfNodeGroup.h \
    src/sbfEnums.h \
    src/sbfSElement.h \
    src/sbfSELevel.h \
    src/sbfSELevelList.h \
    src/sbfDeclspec.h \
    src/sbfPropertyTable.h \
    src/sbfMaterialProperties.h \
    src/sbfPropertiesSet.h \
    src/sbfStiffBlock3x3.h \
    src/sbfStiffMatrixBlock3x3.h \
    src/sbfElemStiffMatrixHexa8.h \
    src/sbfWorker.h \
    src/sbfParallelTask.h \
    src/sbfReporter.h \
    src/sbfTimer.h \
    src/sbfMatrixIterator.h \
    src/sbfStiffMatrixBlock3x3Iterator.h \
    src/sbfMeshBuilders.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = ~/lib
    }
    INSTALLS += target
}

OTHER_FILES += \
    CMakeLists.txt
