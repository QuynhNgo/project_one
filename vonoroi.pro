#-------------------------------------------------
#
# Project created by QtCreator 2014-04-21T12:03:37
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vonoroi
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    voronoi.cpp \
    point.cpp

HEADERS  += mainwindow.h \
    voronoi.h \
    point.h

FORMS    += mainwindow.ui

QMAKE_LFLAGS += /INCREMENTAL:NO

LIBS+=-lglut32

INCLUDEPATH += C:\\opencv\\build\\include


LIBS += -LC:\\opencv\\build\\x86\\vc10\\lib\
opencv_core248d.lib\
opencv_imgproc248d.lib\
opencv_highgui248d.lib\
opencv_ml248d.lib\
opencv_video248d.lib\
opencv_features2d248d.lib\
opencv_calib3d248d.lib



