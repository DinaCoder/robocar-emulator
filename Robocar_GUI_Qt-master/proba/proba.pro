#-------------------------------------------------
#
# Project created by QtCreator 2016-03-30T21:34:39
#
#-------------------------------------------------

QMAKE_CXXFLAGS  += -std=c++11
QT              += core gui
QT              += concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = proba
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myutilities.cpp

HEADERS  += mainwindow.h \
    myutilities.h

FORMS    += mainwindow.ui
