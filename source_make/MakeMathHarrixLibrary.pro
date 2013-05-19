#-------------------------------------------------
#
# Project created by QtCreator 2013-05-03T18:59:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MakeMathHarrixLibrary
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    QtHarrixLibrary.cpp

HEADERS  += mainwindow.h \
    QtHarrixLibrary.h

FORMS    += mainwindow.ui

win32:RC_FILE = myapp.rc
