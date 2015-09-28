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

QMAKE_CXXFLAGS += -std=c++11
QMAKE_LFLAGS += -Wl,--no-as-needed


SOURCES += main.cpp\
        mainwindow.cpp \
    form_tek_sost_ik.cpp \
    dataTableModel.cpp \
    form_tek_sost_afsz.cpp \
    animwidget.cpp \
    mainform.cpp \
    elemlist.cpp \
    mdl1.cpp \
    form1.cpp \
    form2.cpp \
    ParamTableModel.cpp \
    form3.cpp \
    form_temporary.cpp

HEADERS  += mainwindow.h \
    form_tek_sost_ik.h \
    dataTableModel.h \
    form_tek_sost_afsz.h \
    animwidget.h \
    mainform.h \
    str.h \
    elemlist.h \
    1_list.h \
    mdl1.h \
    form1.h \
    form2.h \
    ParamTableModel.h \
    form3.h \
    form_temporary.h

FORMS    += mainwindow.ui \
    form_tek_sost_afsz.ui \
    form_tek_sost_ik.ui \
    mainform.ui \
    form1.ui \
    form2.ui \
    form3.ui \
    form_temporary.ui

RESOURCES += \
    res1.qrc
