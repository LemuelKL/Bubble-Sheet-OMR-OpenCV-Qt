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
    QTextBrowser *textBrowser_Console;
    QProgressBar *progressBar_Pdf2Img;
    QLineEdit *lineEdit_SetImgPrefix;
    QLabel *label_TextInfo_SetImgPrefix;
    QFrame *line;
    QLabel *label_TextInfo_ConvertedSoFar;
    QComboBox *comboBox_SelectOutImgFormat;
    QPushButton *pushButton_CV_Worker;
    QTextBrowser *textBrowser_ConvertedImagePaths;
    QPushButton *pushButton_PrevPage;
    QPushButton *pushButton_NextPage;
    QLabel *label_CurrentPageNumber;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1200, 651);
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
        textBrowser_Console = new QTextBrowser(centralWidget);
        textBrowser_Console->setObjectName(QStringLiteral("textBrowser_Console"));
        textBrowser_Console->setGeometry(QRect(380, 10, 811, 191));
        textBrowser_Console->setFocusPolicy(Qt::StrongFocus);
        textBrowser_Console->setAutoFillBackground(false);
        textBrowser_Console->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textBrowser_Console->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        textBrowser_Console->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        textBrowser_Console->setLineWrapMode(QTextEdit::NoWrap);
        progressBar_Pdf2Img = new QProgressBar(centralWidget);
        progressBar_Pdf2Img->setObjectName(QStringLiteral("progressBar_Pdf2Img"));
        progressBar_Pdf2Img->setGeometry(QRect(640, 240, 231, 21));
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
        line->setGeometry(QRect(380, 260, 811, 21));
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
        pushButton_CV_Worker = new QPushButton(centralWidget);
        pushButton_CV_Worker->setObjectName(QStringLiteral("pushButton_CV_Worker"));
        pushButton_CV_Worker->setGeometry(QRect(380, 280, 91, 51));
        textBrowser_ConvertedImagePaths = new QTextBrowser(centralWidget);
        textBrowser_ConvertedImagePaths->setObjectName(QStringLiteral("textBrowser_ConvertedImagePaths"));
        textBrowser_ConvertedImagePaths->setGeometry(QRect(880, 210, 311, 51));
        textBrowser_ConvertedImagePaths->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser_ConvertedImagePaths->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        pushButton_PrevPage = new QPushButton(centralWidget);
        pushButton_PrevPage->setObjectName(QStringLiteral("pushButton_PrevPage"));
        pushButton_PrevPage->setGeometry(QRect(380, 530, 71, 41));
        pushButton_NextPage = new QPushButton(centralWidget);
        pushButton_NextPage->setObjectName(QStringLiteral("pushButton_NextPage"));
        pushButton_NextPage->setGeometry(QRect(460, 530, 71, 41));
        label_CurrentPageNumber = new QLabel(centralWidget);
        label_CurrentPageNumber->setObjectName(QStringLiteral("label_CurrentPageNumber"));
        label_CurrentPageNumber->setGeometry(QRect(540, 530, 41, 41));
        QFont font2;
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(true);
        font2.setWeight(75);
        font2.setStrikeOut(false);
        font2.setKerning(true);
        label_CurrentPageNumber->setFont(font2);
        label_CurrentPageNumber->setCursor(QCursor(Qt::CrossCursor));
        label_CurrentPageNumber->setAutoFillBackground(false);
        label_CurrentPageNumber->setScaledContents(false);
        label_CurrentPageNumber->setAlignment(Qt::AlignCenter);
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
        pushButton_CV_Worker->setText(QApplication::translate("MainWindow", "Start CV Worker", nullptr));
        pushButton_PrevPage->setText(QApplication::translate("MainWindow", "Previous", nullptr));
        pushButton_NextPage->setText(QApplication::translate("MainWindow", "Next", nullptr));
        label_CurrentPageNumber->setText(QApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
