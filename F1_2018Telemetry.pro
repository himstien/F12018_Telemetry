#-------------------------------------------------
#
# Project created by QtCreator 2018-08-24T17:39:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = F1_2018Telemetry
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    PacketHeader.cpp \
    cartelemetrydatapacket.cpp \
    bytestodatatypehelper.cpp

HEADERS  += mainwindow.h \
    PacketHeader.h \
    bytesToDataTypeHelper.h \
    CarPacketData.h \
    CarTelemetryDataPacket.h \
    bytestodatatypehelper.h

FORMS    += mainwindow.ui
