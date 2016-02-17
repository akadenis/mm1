#-------------------------------------------------
#
# Project created by QtCreator 2015-08-11T15:57:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mm1
TEMPLATE = app

CONFIG += c++11

QMAKE_CXXFLAGS += -std=c++11 -pthread
QMAKE_LFLAGS += -Wl,--no-as-needed

QMAKE_CFLAGS +=  -pthread

LIBS += -pthread

SOURCES += main.cpp\
    dataTableModel.cpp \
    ParamTableModel.cpp \
    form3.cpp \
    contentsdlg.cpp \
    shmemthread.cpp \
    ethrecv.cpp \
    ethtesttv.cpp \
    ChannelDataModel.cpp \
    formula.cpp \
    mdlppndata.cpp \
    ppn.cpp \
    ethsend.cpp \
    referenceppn.cpp \
    dlgppn.cpp \
    ref.cpp \
    form3_labelcolor.cpp \
    form3_slideFailConnect.cpp \
    form.cpp \
    form3_slideDiscr.cpp \
    form3_ustav.cpp \
    form3_ppn.cpp \
    form3_slideDiscrTxt.cpp \
    form3_alg.cpp

HEADERS  += \
    dataTableModel.h \
    ParamTableModel.h \
    form3.h \
    contentsdlg.h \
    shmemthread.h \
    packdata.h \
    ethrecv.h \
    ethtesttv.h \
    ChannelDataModel.h \
    formula.h \
    mdlppndata.h \
    ppn.h \
    constants.h \
    referenceppn.h \
    dlgppn.h \
    ref.h \
    form.h

FORMS    += \
    form3.ui \
    referenceppn.ui \
    dlgppn.ui \
    ref.ui

RESOURCES += \
    res1.qrc
