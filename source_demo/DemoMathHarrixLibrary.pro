#-------------------------------------------------
#
# Project created by QtCreator 2013-05-04T21:40:47
#
#-------------------------------------------------

QT       += core gui webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DemoMathHarrixLibrary
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    MathHarrixLibrary.cpp \
    QtHarrixLibrary.cpp \
    QtHarrixLibraryForQWebView.cpp

HEADERS  += mainwindow.h \
    MathHarrixLibrary.h \
    QtHarrixLibrary.h \
    QtHarrixLibraryForQWebView.h

FORMS    += mainwindow.ui

win32:RC_FILE = myapp.rc
