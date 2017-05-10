#-------------------------------------------------
#
# Project created by QtCreator 2017-05-04T00:35:32
#
#-------------------------------------------------

QT       += core gui \
            charts

target.path = $$[QT_INSTALL_EXAMPLES]/charts/barchart
INSTALLS += target

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gra
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    sensordatatype.cpp \
    dailysensortype.cpp \
    montylysensortype.cpp \
    yearlysensortype.cpp \
    datamanager.cpp \
    chart.cpp \
    amonthchart.cpp

HEADERS  += mainwindow.hpp \
    sensordatatype.hpp \
    dailysensortype.hpp \
    montylysensortype.hpp \
    yearlysensortype.hpp \
    datamanager.hpp \
    chart.hpp \
    amonthchart.hpp

FORMS    += mainwindow.ui
