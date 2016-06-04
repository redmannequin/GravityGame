TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -LC:/SDL/lib -lSDL2
INCLUDEPATH += C:/SDL/include/SDL

SOURCES += main.cpp \
    game.cc \
    vector2D.cc \
    polygon.cc

HEADERS += \
    game.h \
    vector2D.h \
    polygon.h
