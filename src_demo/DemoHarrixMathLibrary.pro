#-------------------------------------------------
#
# Project created by QtCreator 2013-05-04T21:40:47
#
#-------------------------------------------------

QT       += core gui webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DemoHarrixMathLibrary
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    HarrixMathLibrary.cpp \
    HarrixQtLibrary.cpp \
    HarrixQtLibraryForQWebView.cpp \
    mtrand.cpp

HEADERS  += mainwindow.h \
    HarrixMathLibrary.h \
    HarrixQtLibrary.h \
    HarrixQtLibraryForQWebView.h \
    mtrand.h

FORMS    += mainwindow.ui

win32:RC_FILE = myapp.rc
