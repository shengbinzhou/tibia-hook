QT += core gui
TEMPLATE = lib
TARGET = hook

QMAKE_CXXFLAGS += -std=gnu++0x

INCLUDEPATH += include ../lib/mologie-detours ../lib/qt-json
DESTDIR = ../bin

SOURCES = src/Application.cpp \
	src/DetourManager.cpp \
	src/Hook.cpp \
	src/Main.cpp \
	src/Settings.cpp \
    src/UIManager.cpp \
    src/PluginManager.cpp \
    src/ProxyManager.cpp

HEADERS = src/Application.h \
	src/DataQueue.h \
	src/DetourManager.h \
	src/DetourSender.h \
	src/Hook.h \
    src/PacketBuilder.h \
	src/Settings.h \
    src/UIManager.h \
    src/PluginManager.h \
    src/ProxyManager.h \
    src/PacketReader.h \
    src/Packet.h
