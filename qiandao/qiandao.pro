#-------------------------------------------------
#
# Project created by QtCreator 2020-02-06T16:10:20
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qiandao
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    personmessage.cpp \
    signer.cpp

HEADERS  += widget.h \
    personmessage.h \
    signer.h

FORMS    += widget.ui \
    personmessage.ui \
    signer.ui

RESOURCES += \
    image.qrc


