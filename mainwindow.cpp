#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <stdio.h>
#include <iostream>
#include <string>

#include <pdf.h>

#include <QDir>
#include <QFileDialog>
#include <QMessageBox>

#include <Magick++.h>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace Magick;
using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Bubble Sheet Optical Mark Recognition");

    //ui->label_displayImg->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, int(img.step), QImage::Format_RGB888)));
    //ui->label_displayImg->setScaledContents( true );

    ui->textBrowser->setText("A\nB\nC");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void singleImgAlgorithm(std::string)
{
    // //
}

void MainWindow::on_pushButton_Choose_PDF_clicked()
{
    QString path2Pdf = QFileDialog::getOpenFileName(
                this,
                tr("Choose PDF"),
                "C:/",
                tr("PDF Files (*.pdf)")
                );
    if (path2Pdf.isEmpty()){
        QMessageBox::warning(this, tr("What are you doing?"), tr("Please select a PDF file."));
    }
    else
    {
        pdf::mFullPath = path2Pdf.toStdString();
        ui->textBrowser->setText(pdf::mFullPath.c_str());
    }
}

void MainWindow::on_pushButton_ConvertPdf2Png_clicked()
{
    if (pdf::mFullPath.size()<1)
    {
        QMessageBox::warning(this, tr("What are you doing?"), tr("Please have a PDF file loaded first."));
    }
    else
    {
        pdf pdfFile(pdf::mFullPath);
        vector<string> ret;
        ret = pdfFile.ConvertToPNGs("D:/Users/Lemuel/Software-Development/Bubble-Sheet-OMR/Bubble-Sheet-OMR-OpenCV-Qt/pdf", "AAA");
        if (ret.size()<1)
        {
            // //
        }
        else
        {
            string converted;
            for(size_t j=0;j!=ret.size();++j)
                converted = converted + ret[j] + "\n";
            ui->textBrowser->setText(converted.c_str());
        }
    }
}
