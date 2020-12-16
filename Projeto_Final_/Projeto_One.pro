TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    sculptor.cpp \
    cutbox.cpp \
    cutvoxel.cpp \
    putbox.cpp \
    putsphere.cpp \
    putvoxel.cpp \
    interpretador.cpp \
    putellipsoid.cpp \
    cutellipsoid.cpp \
    cutsphere.cpp

HEADERS += \
    sculptor.h \
    cutbox.h \
    cutvoxel.h \
    putbox.h \
    putsphere.h \
    putvoxel.h \
    interpretador.h \
    figurageometrica.h \
    putellipsoid.h \
    cutellipsoid.h \
    cutsphere.h

