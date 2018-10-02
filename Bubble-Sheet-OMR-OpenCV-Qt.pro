#-------------------------------------------------
#
# Project created by QtCreator 2018-09-30T13:43:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bubble-Sheet-OMR-OpenCV-Qt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    pdf.cpp

HEADERS += \
        mainwindow.h \
    pdf.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += D:\Users\Lemuel\Software-Development\OpenCV\3.4.2\opencv\build\include \
    "C:\Program Files\ImageMagick-6.9.10-Q16\include"


LIBS += D:\Users\Lemuel\Software-Development\OpenCV\3.4.2\opencv\build\x64\vc15\lib\opencv_world343.lib \
    "C:\Program Files\ImageMagick-6.9.10-Q16\lib\CORE_RL_magick_.lib" \
    "C:\Program Files\ImageMagick-6.9.10-Q16\lib\CORE_RL_Magick++_.lib" \
    "C:\Program Files\ImageMagick-6.9.10-Q16\lib\CORE_RL_wand_.lib"
