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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_Choose_PDF;
    QLabel *label_displayImg;
    QPushButton *pushButton_ConvertPdf2Png;
    QTextBrowser *textBrowser;
    QProgressBar *progressBar_Pdf2Img;
    QLineEdit *lineEdit_SetImgPrefix;
    QLabel *label_TextInfo_SetImgPrefix;
    QFrame *line;
    QLabel *label_TextInfo_ConvertedSoFar;
    QComboBox *comboBox_SelectOutImgFormat;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1200, 640);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(1200, 600));
        pushButton_Choose_PDF = new QPushButton(centralWidget);
        pushButton_Choose_PDF->setObjectName(QStringLiteral("pushButton_Choose_PDF"));
        pushButton_Choose_PDF->setGeometry(QRect(380, 210, 91, 51));
        label_displayImg = new QLabel(centralWidget);
        label_displayImg->setObjectName(QStringLiteral("label_displayImg"));
        label_displayImg->setGeometry(QRect(10, 10, 361, 561));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_displayImg->sizePolicy().hasHeightForWidth());
        label_displayImg->setSizePolicy(sizePolicy1);
        label_displayImg->setAutoFillBackground(false);
        label_displayImg->setFrameShape(QFrame::Box);
        label_displayImg->setFrameShadow(QFrame::Plain);
        label_displayImg->setLineWidth(1);
        pushButton_ConvertPdf2Png = new QPushButton(centralWidget);
        pushButton_ConvertPdf2Png->setObjectName(QStringLiteral("pushButton_ConvertPdf2Png"));
        pushButton_ConvertPdf2Png->setGeometry(QRect(480, 210, 91, 51));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(380, 10, 811, 191));
        textBrowser->setFocusPolicy(Qt::StrongFocus);
        textBrowser->setAutoFillBackground(false);
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        textBrowser->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        textBrowser->setLineWrapMode(QTextEdit::NoWrap);
        progressBar_Pdf2Img = new QProgressBar(centralWidget);
        progressBar_Pdf2Img->setObjectName(QStringLiteral("progressBar_Pdf2Img"));
        progressBar_Pdf2Img->setGeometry(QRect(640, 240, 551, 21));
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        font.setKerning(true);
        progressBar_Pdf2Img->setFont(font);
        progressBar_Pdf2Img->setLayoutDirection(Qt::RightToLeft);
        progressBar_Pdf2Img->setValue(24);
        progressBar_Pdf2Img->setInvertedAppearance(true);
        lineEdit_SetImgPrefix = new QLineEdit(centralWidget);
        lineEdit_SetImgPrefix->setObjectName(QStringLiteral("lineEdit_SetImgPrefix"));
        lineEdit_SetImgPrefix->setGeometry(QRect(680, 210, 131, 21));
        label_TextInfo_SetImgPrefix = new QLabel(centralWidget);
        label_TextInfo_SetImgPrefix->setObjectName(QStringLiteral("label_TextInfo_SetImgPrefix"));
        label_TextInfo_SetImgPrefix->setGeometry(QRect(580, 210, 101, 21));
        QFont font1;
        font1.setPointSize(9);
        label_TextInfo_SetImgPrefix->setFont(font1);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(380, 260, 811, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_TextInfo_ConvertedSoFar = new QLabel(centralWidget);
        label_TextInfo_ConvertedSoFar->setObjectName(QStringLiteral("label_TextInfo_ConvertedSoFar"));
        label_TextInfo_ConvertedSoFar->setGeometry(QRect(580, 240, 61, 21));
        label_TextInfo_ConvertedSoFar->setFont(font1);
        comboBox_SelectOutImgFormat = new QComboBox(centralWidget);
        comboBox_SelectOutImgFormat->addItem(QString());
        comboBox_SelectOutImgFormat->addItem(QString());
        comboBox_SelectOutImgFormat->addItem(QString());
        comboBox_SelectOutImgFormat->setObjectName(QStringLiteral("comboBox_SelectOutImgFormat"));
        comboBox_SelectOutImgFormat->setGeometry(QRect(820, 210, 51, 22));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 21));
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
        pushButton_Choose_PDF->setText(QApplication::translate("MainWindow", "Choose PDF", nullptr));
        label_displayImg->setText(QApplication::translate("MainWindow", "Image", nullptr));
        pushButton_ConvertPdf2Png->setText(QApplication::translate("MainWindow", "Convert PDF", nullptr));
        progressBar_Pdf2Img->setFormat(QApplication::translate("MainWindow", "%p%", nullptr));
        label_TextInfo_SetImgPrefix->setText(QApplication::translate("MainWindow", "Image Prefix : ", nullptr));
        label_TextInfo_ConvertedSoFar->setText(QApplication::translate("MainWindow", "Progress : ", nullptr));
        comboBox_SelectOutImgFormat->setItemText(0, QApplication::translate("MainWindow", ".jpg", nullptr));
        comboBox_SelectOutImgFormat->setItemText(1, QApplication::translate("MainWindow", ".png", nullptr));
        comboBox_SelectOutImgFormat->setItemText(2, QApplication::translate("MainWindow", ".bmp", nullptr));

        comboBox_SelectOutImgFormat->setCurrentText(QApplication::translate("MainWindow", ".jpg", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
