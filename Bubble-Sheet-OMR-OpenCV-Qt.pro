#-------------------------------------------------
#
# Project created by QtCreator 2019-01-12T20:15:25
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
    document.cpp \
    sheet.cpp \
    pdf.cpp \
    frame_displayer.cpp \
    bubble.cpp \
    question.cpp

HEADERS += \
        mainwindow.h \
    document.h \
    sheet.h \
    pdf.h \
    frame_displayer.h \
    bubble.h \
    question.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += D:\Users\Lemuel\Software-Development\OpenCV\3.4.2\opencv\build\include \
    "C:\Program Files\ImageMagick-6.9.10-Q16\include" \
    "D:\Users\Lemuel\Software-Development\Aspose.PDF_for_C++_19.4\include"

LIBS += D:\Users\Lemuel\Software-Development\OpenCV\3.4.2\opencv\build\x64\vc15\lib\opencv_world343.lib \
    "C:\Program Files\ImageMagick-6.9.10-Q16\lib\CORE_RL_magick_.lib" \
    "C:\Program Files\ImageMagick-6.9.10-Q16\lib\CORE_RL_Magick++_.lib" \
    "C:\Program Files\ImageMagick-6.9.10-Q16\lib\CORE_RL_wand_.lib" \
    "D:\Users\Lemuel\Software-Development\Aspose.PDF_for_C++_19.4\lib\Release\Aspose.PDF_vc141x64.lib" \
    "D:\Users\Lemuel\Software-Development\Aspose.PDF_for_C++_19.4\lib\Release\aspose_cpp_vc141x64.lib"
