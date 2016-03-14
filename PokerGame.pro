#-------------------------------------------------
#
# Project created by QtCreator 2016-01-28T17:57:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PokerGame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    card.cpp \
    gamecentralwidget.cpp \
    tutorialwidget.cpp \
    deck.cpp \
    player.cpp

HEADERS  += mainwindow.h \
    gamecentralwidget.h \
    tutorialwidget.h \
    card.h \
    deck.h \
    player.h

FORMS    += mainwindow.ui \
    gamecentralwidget.ui \
    tutorialwidget.ui


RESOURCES += \
    images.qrc

QMAKE_CXXFLAGS = -mmacosx-version-min=10.7 -std=gnu0x -stdlib=libc++

CONFIG += c++11
