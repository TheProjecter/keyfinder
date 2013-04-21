#-------------------------------------------------
#
# Project created by QtCreator 2013-04-18T21:11:15
#
#-------------------------------------------------
#/**
 #*This work is licensed under the
 #*Creative Commons Attribuzione 3.0
 #*Unported License. To view a copy
 #*of this license, visit
 #*http://creativecommons.org/licenses/by/3.0/
 #*@author Raffaele Pertile <raffarti@gmail.com>
 #*/
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KeyFinder

TEMPLATE = app


SOURCES += main.cpp \
    keyprinter.cpp \
    mainwindow.cpp \
    layer.cpp \
    listener.cpp

HEADERS += \
    keyprinter.h \
    mainwindow.h \
    layer.h \
    listener.h

LIBS += -lX11 -lXtst

FORMS += \
    mainwindow.ui \
    layer.ui
