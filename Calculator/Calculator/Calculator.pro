#-------------------------------------------------
#
# Project created by QtCreator 2016-06-01T17:15:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calculator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    fileio.cpp \
    Calculation.cpp \
    Scan.cpp \
    Print.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    fileio.h \
    Calculation.h \
    Scan.h \
    Print.h

FORMS    += mainwindow.ui \
    dialog.ui \
    fileio.ui
