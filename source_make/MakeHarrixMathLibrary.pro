#-------------------------------------------------
#
# Project created by QtCreator 2013-05-03T18:59:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MakeHarrixMathLibrary
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    HarrixQtLibrary.cpp

HEADERS  += mainwindow.h \
    HarrixQtLibrary.h

FORMS    += mainwindow.ui

win32:RC_FILE = myapp.rc
