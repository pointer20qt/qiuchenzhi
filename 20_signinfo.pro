#-------------------------------------------------
#
# Project created by QtCreator 2020-02-07T12:25:15
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 20_signinfo
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    presonwidght.cpp \
    login.cpp \
    registration.cpp

HEADERS  += widget.h \
    presonwidght.h \
    login.h \
    registration.h

FORMS    += widget.ui \
    presonwidght.ui \
    login.ui \
    registration.ui

RESOURCES += \
    res.qrc
