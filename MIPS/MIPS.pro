#-------------------------------------------------
#
# Project created by QtCreator 2016-06-19T13:04:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MIPS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    assembler.cpp

HEADERS  += mainwindow.h \
    assembler.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
