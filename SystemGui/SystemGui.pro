#-------------------------------------------------
#
# Project created by QtCreator 2016-09-09T23:33:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SystemGui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        connect_tcp_client.cpp

HEADERS  += mainwindow.h\
         connect_tcp_client.h

FORMS    += mainwindow.ui

CONFIG += c++11
