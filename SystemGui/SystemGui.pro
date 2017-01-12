#-------------------------------------------------
#
# Project created by QtCreator 2016-09-09T23:33:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SystemGui
TEMPLATE = app

CONFIG += c++11
CONFIG += console


SOURCES += main.cpp\
        mainwindow.cpp\
        connect_tcp_client.cpp\
        parameter.cpp

HEADERS  += mainwindow.h\
         connect_tcp_client.h\
         parameter.h


FORMS    += mainwindow.ui
