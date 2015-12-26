#-------------------------------------------------
#
# Project created by QtCreator 2014-11-15T15:36:33
#
#-------------------------------------------------


TARGET = gameFallout3
TEMPLATE = lib

CONFIG += plugins
CONFIG += dll

DEFINES += GAMEFALLOUT4_LIBRARY

SOURCES += gamefallout4.cpp \
    fallout4bsainvalidation.cpp \
    fallout4scriptextender.cpp \
    fallout4dataarchives.cpp \
    fallout4savegame.cpp \
    fallout4savegameinfo.cpp

HEADERS += gamefallout4.h \
    fallout4bsainvalidation.h \
    fallout4scriptextender.h \
    fallout4dataarchives.h \
    fallout4savegame.h \
    fallout4savegameinfo.h

CONFIG(debug, debug|release) {
  LIBS += -L"$${OUT_PWD}/../gameGamebryo/debug"
  PRE_TARGETDEPS += \
    $$OUT_PWD/../gameGamebryo/debug/gameGamebryo.lib
} else {
  LIBS += -L"$${OUT_PWD}/../gameGamebryo/release"
  PRE_TARGETDEPS += \
    $$OUT_PWD/../gameGamebryo/release/gameGamebryo.lib
}

include(../plugin_template.pri)

INCLUDEPATH += "$${BOOSTPATH}" "$${PWD}/../gamefeatures" "$${PWD}/../gamegamebryo"

LIBS += -ladvapi32 -lole32 -lgameGamebryo

OTHER_FILES += \
    gamefallout4.json\
    SConscript \
    CMakeLists.txt

