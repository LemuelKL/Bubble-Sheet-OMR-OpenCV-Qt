/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "frame_displayer.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    frame_displayer *label_FrameDisplayer;
    QPushButton *pushButton_ImportPDF;
    QProgressBar *progressBar_ConversionDone;
    QFrame *line;
    QPushButton *pushButton_Marking_Generic;
    QPushButton *pushButton_PreviousSheet;
    QPushButton *pushButton_NextSheet;
    QLabel *label_PageNumber;
    QLabel *label_xCoord;
    QLabel *label_yCoord;
    QLabel *label_xCoordHolder;
    QLabel *label_yCoordHolder;
    QSpinBox *spinBox_Marking_startPage;
    QSpinBox *spinBox_Marking_endPage;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 800);
        MainWindow->setMinimumSize(QSize(800, 800));
        MainWindow->setMaximumSize(QSize(800, 800));
        MainWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_FrameDisplayer = new frame_displayer(centralWidget);
        label_FrameDisplayer->setObjectName(QStringLiteral("label_FrameDisplayer"));
        label_FrameDisplayer->setGeometry(QRect(10, 10, 500, 707));
        label_FrameDisplayer->setAutoFillBackground(false);
        label_FrameDisplayer->setFrameShape(QFrame::WinPanel);
        label_FrameDisplayer->setFrameShadow(QFrame::Raised);
        label_FrameDisplayer->setTextFormat(Qt::PlainText);
        label_FrameDisplayer->setScaledContents(true);
        pushButton_ImportPDF = new QPushButton(centralWidget);
        pushButton_ImportPDF->setObjectName(QStringLiteral("pushButton_ImportPDF"));
        pushButton_ImportPDF->setGeometry(QRect(520, 10, 91, 51));
        progressBar_ConversionDone = new QProgressBar(centralWidget);
        progressBar_ConversionDone->setObjectName(QStringLiteral("progressBar_ConversionDone"));
        progressBar_ConversionDone->setGeometry(QRect(520, 70, 271, 21));
        progressBar_ConversionDone->setValue(0);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(520, 100, 271, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        pushButton_Marking_Generic = new QPushButton(centralWidget);
        pushButton_Marking_Generic->setObjectName(QStringLiteral("pushButton_Marking_Generic"));
        pushButton_Marking_Generic->setGeometry(QRect(520, 120, 91, 51));
        pushButton_PreviousSheet = new QPushButton(centralWidget);
        pushButton_PreviousSheet->setObjectName(QStringLiteral("pushButton_PreviousSheet"));
        pushButton_PreviousSheet->setGeometry(QRect(570, 670, 71, 41));
        pushButton_NextSheet = new QPushButton(centralWidget);
        pushButton_NextSheet->setObjectName(QStringLiteral("pushButton_NextSheet"));
        pushButton_NextSheet->setGeometry(QRect(650, 670, 71, 41));
        label_PageNumber = new QLabel(centralWidget);
        label_PageNumber->setObjectName(QStringLiteral("label_PageNumber"));
        label_PageNumber->setGeometry(QRect(520, 670, 41, 41));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_PageNumber->setFont(font);
        label_PageNumber->setAlignment(Qt::AlignCenter);
        label_xCoord = new QLabel(centralWidget);
        label_xCoord->setObjectName(QStringLiteral("label_xCoord"));
        label_xCoord->setGeometry(QRect(400, 720, 16, 16));
        label_yCoord = new QLabel(centralWidget);
        label_yCoord->setObjectName(QStringLiteral("label_yCoord"));
        label_yCoord->setGeometry(QRect(460, 720, 16, 16));
        label_xCoordHolder = new QLabel(centralWidget);
        label_xCoordHolder->setObjectName(QStringLiteral("label_xCoordHolder"));
        label_xCoordHolder->setGeometry(QRect(410, 720, 41, 16));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_xCoordHolder->setFont(font1);
        label_xCoordHolder->setAlignment(Qt::AlignCenter);
        label_yCoordHolder = new QLabel(centralWidget);
        label_yCoordHolder->setObjectName(QStringLiteral("label_yCoordHolder"));
        label_yCoordHolder->setGeometry(QRect(470, 720, 41, 16));
        label_yCoordHolder->setFont(font1);
        label_yCoordHolder->setAlignment(Qt::AlignCenter);
        spinBox_Marking_startPage = new QSpinBox(centralWidget);
        spinBox_Marking_startPage->setObjectName(QStringLiteral("spinBox_Marking_startPage"));
        spinBox_Marking_startPage->setGeometry(QRect(520, 180, 42, 22));
        spinBox_Marking_startPage->setMinimum(1);
        spinBox_Marking_endPage = new QSpinBox(centralWidget);
        spinBox_Marking_endPage->setObjectName(QStringLiteral("spinBox_Marking_endPage"));
        spinBox_Marking_endPage->setGeometry(QRect(570, 180, 42, 22));
        spinBox_Marking_endPage->setMinimum(0);
        spinBox_Marking_endPage->setMaximum(0);
        spinBox_Marking_endPage->setValue(0);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_FrameDisplayer->setText(QString());
        pushButton_ImportPDF->setText(QApplication::translate("MainWindow", "Import PDF", nullptr));
        pushButton_Marking_Generic->setText(QApplication::translate("MainWindow", "Generic", nullptr));
        pushButton_PreviousSheet->setText(QApplication::translate("MainWindow", "Previous", nullptr));
        pushButton_NextSheet->setText(QApplication::translate("MainWindow", "Next", nullptr));
        label_PageNumber->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_xCoord->setText(QApplication::translate("MainWindow", "x: ", nullptr));
        label_yCoord->setText(QApplication::translate("MainWindow", "y: ", nullptr));
        label_xCoordHolder->setText(QString());
        label_yCoordHolder->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
